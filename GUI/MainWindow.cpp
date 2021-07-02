#include "MainWindow.hpp"
#include "./ui_MainWindow.h"

#include "GFA.hpp"
#include "FaaRay.hpp"
#include <QGraphicsRectItem>
#include <QTime>

#include "GUIViewPlane.hpp"
#include <iostream>
#include <stdlib.h>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , renderThreadSPtr_(nullptr)
{
    ui_->setupUi(this);
    setWindowTitle(tr("FAARay"));

    std::shared_ptr<RenderWidget>  renderWidgetSPtr(new RenderWidget(ui_->width->value(), ui_->height->value()));
    renderWidgetSPtr_ = renderWidgetSPtr;

    ui_->renderLayout->addWidget(renderWidgetSPtr_.get());

    connect(ui_->render, SIGNAL(clicked()), this, SLOT(render()));

    // OGL update timer
    // NeedFix: What exactly does this do ?
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(updateOGL()));

    constructDebug("MainWindow");
}

MainWindow::~MainWindow()
{
    sPtrDebug("MainWindow:renderWidgetSPtr_", renderWidgetSPtr_);
    deconstructDebug("MainWindow");
}

void MainWindow::updateOGL() const
{
    renderWidgetSPtr_->update();
}

void MainWindow::viewPlaneSetup_() const
{
    // Get shared viewplane pointer
    std::shared_ptr<FaaRay::RenderJob> renderJobSPtr(renderThreadSPtr_->getRenderJobSPtr());
    FaaRay::ViewPlaneSPtr viewPlaneSPtr = renderJobSPtr->getViewPlaneSPtr();

    viewPlaneSPtr->setNumSamples(ui_->samples->value());
    ui_->samples->setValue(viewPlaneSPtr->numSamples());
}

void MainWindow::sceneBuild_() const
{
    // Get scene pointer
    std::shared_ptr<FaaRay::RenderJob> renderJobSPtr(renderThreadSPtr_->getRenderJobSPtr());
    std::shared_ptr<FaaRay::Scene> sceneSPtr(renderJobSPtr->getSceneSPtr());

    // create shared Pin Hole Camera and add to scene
    FaaRay::PinholeCameraSPtr  cameraSPtr(new FaaRay::PinholeCamera);
    cameraSPtr->setEye(GFA::Point3D(
            ui_->cameraX->value(),
            ui_->cameraY->value(),
            ui_->cameraZ->value()));
    cameraSPtr->setLookAt(GFA::Point3D(
            ui_->lookAtX->value(),
            ui_->lookAtY->value(),
            ui_->lookAtZ->value()));
            
    cameraSPtr->setViewPlaneDistance(ui_->vpDistance->value());
    cameraSPtr->setZoom(ui_->zoom->value());
    sceneSPtr->setCamera(cameraSPtr);

    // Create tracer and add to scene
    FaaRay::TracerSPtr tracerSPtr(nullptr);
    switch (ui_->tracer->currentIndex()) {
        case 0:
            tracerSPtr = FaaRay::MakeRayCastTracerSPtr();
            break;
        default:
            tracerSPtr = FaaRay::MakeRayCastTracerSPtr();
            ui_->tracer->setCurrentIndex(0);
            break;
    }
    sceneSPtr->setTracer(tracerSPtr);

    // Create ambient light and add to scene
    FaaRay::AmbientLightSPtr ambientLightSPtr(nullptr);
    switch (ui_->ambient->currentIndex()) {
        case 0:
            ambientLightSPtr = FaaRay::MakeAmbientLightSPtr();
            break;
        default:
            ambientLightSPtr = FaaRay::MakeAmbientLightSPtr();
            ui_->ambient->setCurrentIndex(0);
            break;
    }
    ambientLightSPtr->setLs(ui_->ambientRadiance->value());
    sceneSPtr->setAmbientLight(ambientLightSPtr);

    // NeedFix: why does this not work ??
    //PointLightSPtr pointLightASPtr;
    //pointLightASPtr = MakePointLightSPtr;

    FaaRay::PointLightSPtr pointLightASPtr(new FaaRay::PointLight);
    
    pointLightASPtr->setCenter(-10, 10, 10);
    pointLightASPtr->setColor(GFA::RGBColor(1, 1, 1));
    pointLightASPtr->setRadiance(0.7);
    pointLightASPtr->castShadows(true);
    sceneSPtr->addLight(pointLightASPtr);
    
    pointLightASPtr.reset(new FaaRay::PointLight);
    
    pointLightASPtr->setCenter(200, 200, 200);
    pointLightASPtr->setColor(GFA::RGBColor(1, 1, 1));
    pointLightASPtr->setRadiance(0.7);
    pointLightASPtr->castShadows(true);
    sceneSPtr->addLight(pointLightASPtr);

    // create MatteMaterials for objects
    FaaRay::MatteMaterialSPtr matteMaterialASPtr(new FaaRay::MatteMaterial);
    matteMaterialASPtr->setCd(GFA::RGBColor(1.0, 1.0, 0.0));
    matteMaterialASPtr->setKd(1.5);
    
    FaaRay::MatteMaterialSPtr matteMaterialBSPtr(new FaaRay::MatteMaterial);
    matteMaterialBSPtr->setCd(GFA::RGBColor(0.5, 0.5, 1.0));
    matteMaterialBSPtr->setKd(1.5);
    
    FaaRay::PhongMaterialSPtr phongMaterialASPtr(new FaaRay::PhongMaterial);
    phongMaterialASPtr->setCd(GFA::RGBColor(1.0, 1.0, 0.3));
    phongMaterialASPtr->setKd(1.5);
    phongMaterialASPtr->setCs(GFA::RGBColor(1.0, 1.0, 1.0));
    phongMaterialASPtr->setKs(0.5);
    phongMaterialASPtr->setExp(20.0);
    
    FaaRay::PhongMaterialSPtr phongMaterialBSPtr(new FaaRay::PhongMaterial);
    phongMaterialBSPtr->setCd(GFA::RGBColor(0.3, 0.3, 1.0));
    phongMaterialBSPtr->setKd(1.5);
    phongMaterialBSPtr->setCs(GFA::RGBColor(1.0, 1.0, 0.3));
    phongMaterialBSPtr->setKs(0.5);
    phongMaterialBSPtr->setExp(20.0);

    // Create sphere array and add to scene
    /*
    FaaRay::SphereSPtr sphereSPtr;
    for (GFA::Index x = 0; x < 20; x ++) {
        for (GFA::Index y = 0; y < 20; y ++) {
            // No need to reset pointer, does it automatically
            sphereSPtr = FaaRay::MakeSphereSPtr();
            sphereSPtr->setCenter((x*1.5)-14.25, (y*1.5)-14.25, 0.0);
            sphereSPtr->setRadius(((0.75/20) * (x+1)) * ((y+1)/20.0));
            sphereSPtr->setMaterialSPtr(phongMaterialASPtr);
            sceneSPtr->addObject(sphereSPtr);
        }
    }
    */
    // Objects
    FaaRay::SphereSPtr sphereSPtr;
    sphereSPtr = FaaRay::MakeSphereSPtr();
    sphereSPtr->setCenter(0, 0, 0);
    sphereSPtr->setRadius(6);
    sphereSPtr->setMaterialSPtr(phongMaterialASPtr);
    sceneSPtr->addObject(sphereSPtr);
    sphereSPtr = FaaRay::MakeSphereSPtr();
    sphereSPtr->setCenter(5, 15, 15);
    sphereSPtr->setRadius(4);
    sphereSPtr->setMaterialSPtr(phongMaterialASPtr);
    sceneSPtr->addObject(sphereSPtr);

    FaaRay::PlaneSPtr planeSPtr;
    planeSPtr = FaaRay::MakePlaneSPtr();
    planeSPtr->setCenter(0, 0, 0);
    planeSPtr->setNormal(0, 1, 0);
    planeSPtr->setMaterialSPtr(phongMaterialASPtr);
    sceneSPtr->addObject(planeSPtr);

    FaaRay::OpenCylinderSPtr openCylinderSPtr;
    openCylinderSPtr = FaaRay::MakeOpenCylinderSPtr();
    openCylinderSPtr->setCenter(0, 7, 0);
    openCylinderSPtr->setBottom(0);
    openCylinderSPtr->setTop(6);
    openCylinderSPtr->setRadius(4);
    openCylinderSPtr->setMaterialSPtr(phongMaterialBSPtr);
    sceneSPtr->addObject(openCylinderSPtr);

    FaaRay::DiscSPtr discSPtr;
    discSPtr = FaaRay::MakeDiscSPtr();
    discSPtr->setCenter(0, 4, 0);
    discSPtr->setRadius(6);
    discSPtr->setMaterialSPtr(phongMaterialASPtr);
    sceneSPtr->addObject(discSPtr);

    /* Cover problem
    SphereSPtr sphereSPtr;

    sphereSPtr = MakeSphereSPtr();
    sphereSPtr->setCenter(-5.0, 0, 0);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialASPtr);
    sceneSPtr->addObject(sphereSPtr);

    sphereSPtr = MakeSphereSPtr();
    sphereSPtr->setCenter(0, 0, -10);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialBSPtr);
    sceneSPtr->addObject(sphereSPtr);
    */

    // Create 2 sphere
    /*
    SphereSPtr sphereSPtr(new Sphere);
    sphereSPtr->setCenter(-5, 0, 0);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialASPtr);
    sceneSPtr->addObject(sphereSPtr);

    sphereSPtr = MakeSphereSPtr();
    sphereSPtr->setCenter(5, 0, 2);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialASPtr);
    sceneSPtr->addObject(sphereSPtr);
    */

    /*
    Sphere* spherePtr;
    spherePtr = new Sphere;
    spherePtr->setCenter(2.2, 0.0, 0.0);
    spherePtr->setRadius(1.0);
    spherePtr->setMaterial(matteMaterialAPtr);
    addObject(spherePtr);
    spherePtr = new Sphere;
    spherePtr->setCenter(-2.2, 0.0, 0.0);
    spherePtr->setRadius(1.0);
    spherePtr->setMaterial(phongMaterialAPtr);
    addObject(spherePtr);
    spherePtr = new Sphere;
    spherePtr->setCenter(0.0, 0.0, 2.2);
    spherePtr->setRadius(1.0);
    spherePtr->setMaterial(phongMaterialAPtr);
    addObject(spherePtr);
    spherePtr = new Sphere;
    spherePtr->setCenter(0.0, 0.0, -2.2);
    spherePtr->setRadius(1.0);
    spherePtr->setMaterial(emissiveMaterialAPtr);
    addObject(spherePtr);
    */

    /*
    OpenCylinder* cylinderPtr = new OpenCylinder(-1.0, 2.0, 0.0);
    cylinderPtr->setMaterial(phongMaterialAPtr);
    addObject(cylinderPtr);
    
    Plane* planePtr = new Plane(GFA::Point3D(0.0, -1.0, 0.0), Normal(0.0, 1.0, 0.0));
    planePtr->setMaterial(phongMaterialBPtr);
    addObject(planePtr);
    
    Disc* discPtr = new Disc(GFA::Point3D(1.5, 1.4, 0.5), Normal(0.0, 1.0, 0.0), 1.0);
    discPtr->setMaterial(matteMaterialAPtr);
    addObject(discPtr);

    Rectangle* rectanglePtr = new Rectangle(GFA::Point3D(0.0, 1.5, 0.0), Vector3D(2.0, 0.0, 0.0), Vector3D(1.0, 0.0, -1.0));
    rectanglePtr->setMaterial(matteMaterialAPtr);
    addObject(rectanglePtr);
    */

}

void MainWindow::render()
{
    std::cout << "\n**** MainWindow:render ****\n";
    ui_->render->setDisabled(true);

    std::shared_ptr<FaaRay::RenderJob> renderJobSPtr(new FaaRay::RenderJob);
    renderThreadSPtr_.reset(new RenderThread(renderJobSPtr));

    // Initialize render buffer
    renderWidgetSPtr_->resizeBuffer(ui_->width->value(), ui_->height->value());
    
    // Create render job
    QTime rjTimer(0,0);

    // Replace renderjob viewplane by specifically designed viewplane 
    // for this gui based on ViewPlane
    // NeedFix: this might be done with shared pointer reset ?
    GUIViewPlaneSPtr viewPlaneSPtr(new GUIViewPlane(renderWidgetSPtr_));
    // NeedFix: Doesn't the viewPlane get deleted at the end of this proc ??
    renderJobSPtr->setViewPlaneSPtr(viewPlaneSPtr);

    // Setup viewplane and scene
    viewPlaneSetup_();
    sceneBuild_();

    if (ui_->cpus->currentIndex() == 1) renderJobSPtr->setMultiThread();

    updateOGL();

    // Start Qt render tread
    connect(renderThreadSPtr_.get(), SIGNAL(renderDone()),this, SLOT(renderDone()));
    renderThreadSPtr_->start();
}

void MainWindow::renderDone()
{
    std::cout << "\n**** MainWindow:renderDone ****\n";
    renderThreadSPtr_->wait();
    renderThreadSPtr_.reset();

    //timer_->stop();    
    updateOGL();
    
    ui_->render->setDisabled(false);
}


