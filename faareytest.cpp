#include <iostream>
#include "FaaRay.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Running FaaRay test\n";

    FaaRay::RenderJobSPtr renderJobSPtr(new FaaRay::RenderJob);
    
    FaaRay::ViewPlaneSPtr viewPlaneSPtr(new FaaRay::ViewPlane(500, 500));
    renderJobSPtr->setViewPlaneSPtr(viewPlaneSPtr);
    viewPlaneSPtr->setNumSamples(16);
    std::cout << "numSamples: " << viewPlaneSPtr->numSamples() << std::endl;
    
    FaaRay::SceneSPtr sceneSPtr(renderJobSPtr->getSceneSPtr());

    FaaRay::PinholeCameraSPtr  cameraSPtr(new FaaRay::PinholeCamera);
    cameraSPtr->setEye(GFA::Point3D(0, 0, 20));
    cameraSPtr->setLookAt(GFA::Point3D(0, 0, 0));
    cameraSPtr->setViewPlaneDistance(10);
    cameraSPtr->setZoom(1);
    sceneSPtr->setCamera(cameraSPtr);

    FaaRay::RayCastTracerSPtr tracerSPtr(new FaaRay::RayCastTracer);
    sceneSPtr->setTracer(tracerSPtr);

    FaaRay::AmbientLightSPtr ambientLightSPtr(new FaaRay::AmbientLight);
    ambientLightSPtr->setLs(0.05);
    sceneSPtr->setAmbientLight(ambientLightSPtr);

    FaaRay::PointLightSPtr pointLightSPtr(new FaaRay::PointLight);
    pointLightSPtr->setCenter(60, 200, 40);
    pointLightSPtr->setColor(GFA::RGBColor(1, 1, 0.3));
    pointLightSPtr->setRadiance(3);
    pointLightSPtr->castShadows(true);
    sceneSPtr->addLight(pointLightSPtr);

    pointLightSPtr.reset(new FaaRay::PointLight);
    pointLightSPtr->setCenter(40, -40, 40);
    pointLightSPtr->setColor(GFA::RGBColor(0.3, 0.3, 1));
    pointLightSPtr->setRadiance(2);
    pointLightSPtr->castShadows(true);
    sceneSPtr->addLight(pointLightSPtr);

    FaaRay::MatteMaterialSPtr matteMaterialASPtr(new FaaRay::MatteMaterial);
    matteMaterialASPtr->setCd(1.0, 1.0, 1.0);
    FaaRay::MatteMaterialSPtr matteMaterialBSPtr(new FaaRay::MatteMaterial);
    matteMaterialBSPtr->setCd(0.5, 0.5, 1.0);

    FaaRay::SphereSPtr sphereSPtr;
    sphereSPtr = FaaRay::MakeSphereSPtr();
    sphereSPtr->setCenter(0, 0, 0);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialBSPtr);
    sceneSPtr->addObject(sphereSPtr);
    
    sphereSPtr = FaaRay::MakeSphereSPtr();
    sphereSPtr->setCenter(3, 10, 1);
    sphereSPtr->setRadius(5);
    sphereSPtr->setMaterialSPtr(matteMaterialASPtr);
    sceneSPtr->addObject(sphereSPtr);

    std::cout << "Start render\n";
    renderJobSPtr->render();
    std::cout << "End render\n";

    return 0;
}
