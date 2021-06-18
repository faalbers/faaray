#ifndef __FAARAY_TRACETHREAD_H__
#define __FAARAY_TRACETHREAD_H__

#include "Utils/FaaRay.hpp"
#include <memory>
#include "GFA.hpp"
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Normal.hpp"
#include "RGBColor.hpp"


class ViewPlane;
class Scene;
class Sampler;
class Tracer;
class Light;
class Material;

class TraceThread
{
public:
    TraceThread();

    void render();
    
    void        initRandom(const uint32_t &s);
    Scalar rand();

    // shared between threads, objects need to be const
    std::shared_ptr<const ViewPlane>    viewPlaneSPtr;
    std::shared_ptr<const Scene>        sceneSPtr;
    std::shared_ptr<const Sampler>      samplerSPtr;
    std::shared_ptr<const Tracer>       tracerSPtr;
    std::shared_ptr<const Light>        ambientLightSPtr;
    
    Scalar      x;
    Scalar      y;
    RGBColor    color;
    uint32_t    seedVal;
    
    // optimization variables

    // viewplane data
    Size       width;
    Size       height;
    Scalar     halfWidth;
    Scalar     halfHeight;
    Scalar     pixelSize;
    
    // sample data
    Index      sampleIndex;
    Index      sampleSetIndex;
    Point2D    sampleUnitSquare;
    Point2D    samplePoint;
    
    // ray data
    Point3D    rayOrigin;
    Vector3D   rayDirection;

    // shadow ray data
    Point3D     sRayOrigin;
    Vector3D    sRayDirection;
    bool        sRayInShadow;

    // ShadeRec (surface) data
    Normal                         srNormal;
    Point3D                        srHitPoint;
    RGBColor                       srColor;
    RGBColor                       srAmbientL;
    RGBColor                       srLightL;
    RGBColor                       srRhoColor;
    RGBColor                       srFColor;
    bool                                srHitAnObject;
    std::shared_ptr<const Material>     srMaterialSPtr; // gets changed per hit point

    // light data
    Vector3D   lDirection;
    
private:
    uint32_t    seedValue_;
    MyRNG       rng_;
    std::uniform_real_distribution<Scalar> distribution;  
};

#endif

