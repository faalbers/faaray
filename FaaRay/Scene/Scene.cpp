
#include "Scene.hpp"
#include <memory>
#include "Cameras/Camera.hpp"
#include "Tracers/Tracer.hpp"
#include "Lights/Light.hpp"
#include "Render/TraceThread.hpp"
#include "GeometricObjects/GeometricObject.hpp"
#include "GeometricObjects/Sphere.hpp"
#include "Materials/Material.hpp"

//#define FAARAY_CLASS_DEBUG

Scene::Scene()
    : cameraSPtr_(nullptr)
    , tracerSPtr_(nullptr)
    , ambientLightSPtr_(nullptr)
{
    constructDebug("Scene");
}

Scene::~Scene()
{
    sPtrDebug("Scene::cameraSPtr_", cameraSPtr_);
    sPtrDebug("Scene::tracerSPtr_", tracerSPtr_);
    sPtrDebug("Scene::ambientLightSPtr_", ambientLightSPtr_);
    for (Index j = 0; j < objectSPtrs_.size(); j++)
        sPtrDebug("Scene::objectSPtrs_", objectSPtrs_[j], j);
    for (Index j = 0; j < lightSPtrs_.size(); j++)
        sPtrDebug(("Scene::lightSPtrs_"), lightSPtrs_[j], j);

    deconstructDebug("Scene");
}

void Scene::setCamera(CameraSPtr cameraSPtr)
{
    cameraSPtr_ = cameraSPtr;
    cameraSPtr_->computeUVW();
}

void Scene::setTracer(TracerSPtr tracerSPtr)
{
    tracerSPtr_ = tracerSPtr;
}

void Scene::setAmbientLight(LightSPtr ambientLightSPtr)
{
    ambientLightSPtr_ = ambientLightSPtr;
}

void Scene::addLight(LightSPtr lightSPtr)
{                                       
    lightSPtrs_.push_back(lightSPtr);
}

void Scene::addObject(GeometricObjectSPtr objectSPtr)
{                                       
    objectSPtrs_.push_back(objectSPtr);
}

CameraSPtr Scene::getCameraSPtr() const
{
    return cameraSPtr_;
}

const Tracer * Scene::getTracerPtr() const
{
    return tracerSPtr_.get();
}

TracerSPtr Scene::getTracerSPtr() const
{
    return tracerSPtr_;
}

ConstTracerSPtr Scene::getConstTracerSPtr() const
{
    return tracerSPtr_;
}

ConstLightSPtr Scene::getConstAmbientLightSPtr() const
{
    return ambientLightSPtr_;
}

void Scene::printSPtrUseCounts()
{
    std::cout << "\nScene: Shared Pointers use count:\n";
    std::cout << "cameraSPtr:\t" << cameraSPtr_.use_count() << std::endl;
    std::cout << "tracerSPtr:\t" << tracerSPtr_.use_count() << std::endl;
    std::cout << "cameraSPtr:\t" << ambientLightSPtr_.use_count() << std::endl;
    for (Index j = 0; j < objectSPtrs_.size(); j++)
        std::cout << "objectSPtr(" << j << "):\t" << objectSPtrs_[j].use_count() << std::endl;
    for (Index j = 0; j < lightSPtrs_.size(); j++)
        std::cout << "lightSPtrs_(" << j << "):\t" << lightSPtrs_[j].use_count() << std::endl;
    
}

void Scene::hitObjects(TraceThread &ttRef) const
{
    Scalar t;
    Scalar tmin = HUGE_SCALAR;
    Index  closestHit = 0;

    // Find closest hit
    ttRef.srHitAnObject = false;
    for (Index j = 0; j < objectSPtrs_.size(); j++) {
        if (objectSPtrs_[j]->hit(ttRef, t) && (t < tmin)) {
            ttRef.srHitAnObject = true;
            tmin = t;
            closestHit = j;
        }
    }
    if (ttRef.srHitAnObject) {
        // no need to delete prior srMaterialSPtr, this happens automatically
        ttRef.srMaterialSPtr = objectSPtrs_[closestHit]->getMaterialSPtr();
        ttRef.srHitPoint = ttRef.rayOrigin + ttRef.rayDirection * t;
    }
}

void Scene::shadowHitObjects(TraceThread &ttRef) const
{
    Scalar t;

    for (Index j = 0; j < objectSPtrs_.size(); j++) {
        if ( objectSPtrs_[j]->shadowHit(ttRef, t) ) {
            ttRef.sRayInShadow = true;
            return;
        }
    }
    ttRef.sRayInShadow = false;
}

void Scene::applyLights(TraceThread &ttRef) const
{   int tempy;
    Scalar ndotwi;
    for (Index j = 0; j < lightSPtrs_.size(); j++) {
        // get light direction vector from light to hit point
        lightSPtrs_[j]->getDirection(ttRef);
        // get multiplier between light and surface vectors
        ndotwi = ttRef.lDirection * ttRef.srNormal;
        if (ndotwi > 0.0) {
            if (lightSPtrs_[j]->castsShadows()) {
                ttRef.sRayOrigin = ttRef.srHitPoint;
                ttRef.sRayDirection = ttRef.lDirection;
                // check if surface point is obscured from the light by any other object
                shadowHitObjects(ttRef);
            }

            if ( !ttRef.sRayInShadow ) {
                lightSPtrs_[j]->L(ttRef);
                ttRef.srColor += ttRef.srFColor * ttRef.srLightL * ndotwi;
            }
        }
    }
}
/*
            bool inShadow = false;
            
            if ( sr.world.lights[j]->castsShadows() ) {
                Ray shadowRay(sr.hitPoint, wi);
                inShadow = sr.world.lights[j]->inShadow(shadowRay, sr);
            }
            if (!inShadow) 
                L += diffuseBrdf->f(sr, wi, wo) * sr.world.lights[j]->L(sr) * ndotwi;
*/

/*
    for (Index j = 0; j < numLights; j++) {
        Vector3D wi = sr.world.lights[j]->getDirection(sr);
        double ndotwi = wi * sr.normal;
        
        if (ndotwi > 0.0) {
            bool inShadow = false;
            
            if ( sr.world.lights[j]->castsShadows() ) {
                Ray shadowRay(sr.hitPoint, wi);
                inShadow = sr.world.lights[j]->inShadow(shadowRay, sr);
            }
            if (!inShadow) 
                L += diffuseBrdf->f(sr, wi, wo) * sr.world.lights[j]->L(sr) * ndotwi;
        }
    }
*/
