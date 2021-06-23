#ifndef __FAARAY_TRACETHREAD_H__
#define __FAARAY_TRACETHREAD_H__

#include "Shared/Shared.hpp"

#include <memory>

class ViewPlane;
class Scene;
class Sampler;
class Tracer;
class Light;
class Material;

class TraceThread : public Base
{
public:
    TraceThread();
    ~TraceThread();

    void render();
    
    void        initRandom(const uint32_t &s);
    GFA::Scalar rand();

    // shared between threads, objects need to be const
    std::shared_ptr<const ViewPlane>    viewPlaneSPtr;
    std::shared_ptr<const Scene>        sceneSPtr;
    std::shared_ptr<const Sampler>      samplerSPtr;
    std::shared_ptr<const Tracer>       tracerSPtr;
    std::shared_ptr<const Light>        ambientLightSPtr;
    
    GFA::Scalar      x;
    GFA::Scalar      y;
    GFA::RGBColor    color;
    uint32_t    seedVal;
    
    // optimization variables

    // viewplane data
    GFA::Size       width;
    GFA::Size       height;
    GFA::Scalar     halfWidth;
    GFA::Scalar     halfHeight;
    GFA::Scalar     pixelSize;
    
    // sample data
    GFA::Index      sampleIndex;
    GFA::Index      sampleSetIndex;
    GFA::Point2D    sampleUnitSquare;
    GFA::Point2D    samplePoint;
    
    // ray data
    GFA::Point3D    rayOrigin;
    GFA::Vector3D   rayDirection;

    // shadow ray data
    GFA::Point3D     sRayOrigin;
    GFA::Vector3D    sRayDirection;
    bool        sRayInShadow;

    // ShadeRec (surface) data
    GFA::Normal                         srNormal;
    GFA::Point3D                        srHitPoint;
    GFA::RGBColor                       srColor;
    GFA::RGBColor                       srAmbientL;
    GFA::RGBColor                       srLightL;
    GFA::RGBColor                       srRhoColor;
    GFA::RGBColor                       srFColor;
    bool                                srHitAnObject;
    std::shared_ptr<const Material>     srMaterialSPtr; // gets changed per hit point

    // light data
    GFA::Vector3D   lDirection;
    
private:
    uint32_t        seedValue_;
    MyRNG           rng_;
    std::uniform_real_distribution<GFA::Scalar> distribution;  
};

#endif

