
#include "Scene/Scene.hpp"
#include "GFA.hpp"
#include <memory>
#include "Cameras/Camera.hpp"
#include "Tracers/Tracer.hpp"
#include "Lights/Light.hpp"
#include "Render/TraceThread.hpp"
#include "GeometricObjects/GeometricObject.hpp"
#include "GeometricObjects/Sphere.hpp"
#include "Materials/Material.hpp"

Scene::Scene(void)
{
}

Scene::~Scene(void)
{
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
