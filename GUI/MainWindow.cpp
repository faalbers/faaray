#include "MainWindow.hpp"
#include "./ui_MainWindow.h"

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
    std::shared_ptr<RenderJob> renderJobSPtr(renderThreadSPtr_->getRenderJobSPtr());
    ViewPlaneSPtr viewPlaneSPtr = renderJobSPtr->getViewPlaneSPtr();

    viewPlaneSPtr->setNumSamples(ui_->samples->value());
    ui_->samples->setValue(viewPlaneSPtr->numSamples());
}

void MainWindow::sceneBuild_() const
{
    // Get scene pointer
    std::shared_ptr<RenderJob> renderJobSPtr(renderThreadSPtr_->getRenderJobSPtr());
    std::shared_ptr<Scene> sceneSPtr(renderJobSPtr->getSceneSPtr());

    // create shared Pin Hole Camera and add to scene
    PinholeCameraSPtr  cameraSPtr(new PinholeCamera);
    cameraSPtr->setEye(Point3D(
            ui_->cameraX->value(),
            ui_->cameraY->value(),
            ui_->cameraZ->value()));
    cameraSPtr->setLookAt(Point3D(
            ui_->lookAtX->value(),
            ui_->lookAtY->value(),
            ui_->lookAtZ->value()));
            
    cameraSPtr->setViewPlaneDistance(ui_->vpDistance->value());
    cameraSPtr->setZoom(ui_->zoom->value());
    sceneSPtr->setCamera(cameraSPtr);

    // Create tracer and add to scene
    TracerSPtr tracerSPtr(nullptr);
    switch (ui_->tracer->currentIndex()) {
        case 0:
            tracerSPtr = MakeRayCastTracerSPtr();
            break;
        default:
            tracerSPtr = MakeRayCastTracerSPtr();
            ui_->tracer->setCurrentIndex(0);
            break;
    }
    sceneSPtr->setTracer(tracerSPtr);

    // Create ambient light and add to scene
    AmbientLightSPtr ambientLightSPtr(nullptr);
    switch (ui_->ambient->currentIndex()) {
        case 0:
            ambientLightSPtr = MakeAmbientLightSPtr();
            break;
        default:
            ambientLightSPtr = MakeAmbientLightSPtr();
            ui_->ambient->setCurrentIndex(0);
            break;
    }
    ambientLightSPtr->setLs(0.05);
    sceneSPtr->setAmbientLight(ambientLightSPtr);

    PointLightSPtr pointLightASPtr(new PointLight);
    pointLightASPtr->setCenter(0, 2000, 0);
    pointLightASPtr->setRadiance(1.5);
    pointLightASPtr->castShadows(false);
    sceneSPtr->addLight(pointLightASPtr);
    
    // create MatteMaterials for objects
    MatteMaterialSPtr matteMaterialASPtr(new MatteMaterial);
    matteMaterialASPtr->setCd(1.0, 1.0, 0.0);

    /*
    // Create sphere array and add to scene
    SphereSPtr sphereSPtr(nullptr);
    for (Index x = 0; x < 20; x ++) {
        for (Index y = 0; y < 20; y ++) {
            // No need to reset pointer, does it automatically
            sphereSPtr = MakeSphereSPtr();
            sphereSPtr->setCenter((x*1.5)-14.25, (y*1.5)-14.25, 0.0);
            sphereSPtr->setRadius(0.75);
            sphereSPtr->setMaterialSPtr(matteMaterialASPtr);
            sceneSPtr->addObject(sphereSPtr);
        }
    }
    
    */
    // Objects
    SphereSPtr sphereSPtr;
    sphereSPtr = MakeSphereSPtr();
    sphereSPtr->setCenter(0, 0, 0);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialASPtr);
    sceneSPtr->addObject(sphereSPtr);
    sphereSPtr = MakeSphereSPtr();
    sphereSPtr->setCenter(0, 0, -10);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialASPtr);
    sceneSPtr->addObject(sphereSPtr);


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

    OpenCylinder* cylinderPtr = new OpenCylinder(-1.0, 2.0, 0.0);
    cylinderPtr->setMaterial(phongMaterialAPtr);
    addObject(cylinderPtr);
    
    Plane* planePtr = new Plane(Point3D(0.0, -1.0, 0.0), Normal(0.0, 1.0, 0.0));
    planePtr->setMaterial(phongMaterialBPtr);
    addObject(planePtr);
    
    Disc* discPtr = new Disc(Point3D(1.5, 1.4, 0.5), Normal(0.0, 1.0, 0.0), 1.0);
    discPtr->setMaterial(matteMaterialAPtr);
    addObject(discPtr);

    Rectangle* rectanglePtr = new Rectangle(Point3D(0.0, 1.5, 0.0), Vector3D(2.0, 0.0, 0.0), Vector3D(1.0, 0.0, -1.0));
    rectanglePtr->setMaterial(matteMaterialAPtr);
    addObject(rectanglePtr);
    */

}

void MainWindow::render()
{
    std::cout << "\n**** MainWindow:render ****\n";
    ui_->render->setDisabled(true);

    std::shared_ptr<RenderJob> renderJobSPtr(new RenderJob);
    renderThreadSPtr_.reset(new RenderThread(renderJobSPtr));

    // Initialize render buffer
    renderWidgetSPtr_->resizeBuffer(ui_->width->value(), ui_->height->value());
    
    // Create render job
    QTime rjTimer(0,0);

    // Replace renderjob viewplane by specifically designed viewplane 
    // for this gui based on ViewPlane
    GUIViewPlaneSPtr viewPlaneSPtr(new GUIViewPlane(renderWidgetSPtr_));
    // NeedFix: Doesn't the viewPlane get deleted at the end of this proc ??
    renderJobSPtr->setViewPlaneSPtr(viewPlaneSPtr);

    // Setup viewplane and scene
    viewPlaneSetup_();
    sceneBuild_();

    if (ui_->cpus->currentIndex() == 1) renderJobSPtr->setMultiThread();
    std::cout << "\nRender Job Creation SEC: " << rjTimer.msecsSinceStartOfDay()/1000.0 << std::endl;

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


