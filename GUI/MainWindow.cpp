#include "MainWindow.hpp"
#include "./ui_MainWindow.h"

#include <QGraphicsRectItem>
#include <QTime>

#include <iostream>
#include <stdlib.h>
#include <memory>

#include "Render/RenderJob.hpp"
#include "Scene/Scene.hpp"
#include "GUIViewPlane.hpp"
#include "Point3D.hpp"
#include "Cameras/PinholeCamera.hpp"
#include "Tracers/RayCastTracer.hpp"
#include "Lights/AmbientLight.hpp"
#include "Lights/PointLight.hpp"
#include "Materials/MatteMaterial.hpp"
#include "GeometricObjects/Sphere.hpp"

MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent),
        ui_(new Ui::MainWindow),
        renderThreadPtr_(nullptr)
{
    ui_->setupUi(this);
    setWindowTitle(tr("FAARay"));

    renderWidgetPtr_ = new RenderWidget(ui_->width->value(), ui_->height->value());

    ui_->renderLayout->addWidget(renderWidgetPtr_);

    connect(ui_->render, SIGNAL(clicked()), this, SLOT(render()));
    //connect(ui_->renderUpdate, SIGNAL(clicked()), this, SLOT(rupdate()));

    // OGL update timer
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(updateOGL()));
}

MainWindow::~MainWindow()
{
    delete renderWidgetPtr_;
}

void MainWindow::updateOGL() const
{
    renderWidgetPtr_->update();
}

void MainWindow::viewPlaneSetup_() const
{
    // Get shared viewplane pointer
    ViewPlaneSPtr viewPlaneSPtr = renderJobPtr_->getViewPlaneSPtr();

    viewPlaneSPtr->setNumSamples(ui_->samples->value());
    ui_->samples->setValue(viewPlaneSPtr->numSamples());
}

void MainWindow::sceneBuild_() const
{
    // Get shared scene pointer
    SceneSPtr sceneSPtr = renderJobPtr_->getSceneSPtr();

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
    pointLightASPtr->setCenter(10, 5, 15);
    pointLightASPtr->setRadiance(2.0);
    pointLightASPtr->castShadows(true);
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
    // Create 2 sphere
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
    
}

void MainWindow::render()
{
    ui_->render->setDisabled(true);

    // Initialize render buffer
    renderWidgetPtr_->resizeBuffer(ui_->width->value(), ui_->height->value());
    
    // Create render job
    QTime rjTimer(0,0);

    renderJobPtr_   = new RenderJob;
    
    // Replace renderjob viewplane by specifically designed viewplane 
    // for this gui based on ViewPlane
    GUIViewPlaneSPtr viewPlaneSPtr(new GUIViewPlane(renderWidgetPtr_));
    renderJobPtr_->setViewPlaneSPtr(viewPlaneSPtr);

    // Setup viewplane and scene
    viewPlaneSetup_();
    sceneBuild_();
    
    if (ui_->cpus->currentIndex() == 1) renderJobPtr_->setMultiThread();
    std::cout << "Render Job Creation SEC: " << rjTimer.msecsSinceStartOfDay()/1000.0 << std::endl;

    updateOGL();

    // Start Qt render tread
    if (renderThreadPtr_ == 0) {
        renderThreadPtr_ = new RenderThread(renderJobPtr_);
        connect(renderThreadPtr_, SIGNAL(renderDone()),this, SLOT(renderDone()));
        renderThreadPtr_->start();
        //timer_->start();   
    }
}

void MainWindow::renderDone()
{
    if (renderThreadPtr_ != 0) {
        renderThreadPtr_->wait();
        delete renderThreadPtr_;
        renderThreadPtr_ = 0;
    }

    // Remove render job
    delete renderJobPtr_; renderJobPtr_ = 0;

    //timer_->stop();    
    updateOGL();
    
    ui_->render->setDisabled(false);
}


