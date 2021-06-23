
#include "RayCastTracer.hpp"
#include "Render/TraceThread.hpp"
#include "Scene/Scene.hpp"
#include "Materials/Material.hpp"

RayCastTracer::RayCastTracer()
{
    constructDebug("RayCastTracer");
}

RayCastTracer::~RayCastTracer()
{
    deconstructDebug("RayCastTracer");
}

void RayCastTracer::traceRay(TraceThread &ttRef) const
{
    ttRef.sceneSPtr->hitObjects(ttRef);
    if(ttRef.srHitAnObject) {
        if ( ttRef.srMaterialSPtr.use_count() != 0) {
            ttRef.srMaterialSPtr->shade(ttRef);
        } else {
            ttRef.srColor = GFA::RGBColor(1, 0, 0, 1);
        }
    } else {
        ttRef.srColor.r = 0.0; ttRef.srColor.g = 0.0; ttRef.srColor.b = 0.0;
    // NeedFix: Does Alpha need to be 0 ?
        ttRef.srColor.a = 0.0;
    }
}

RayCastTracerSPtr MakeRayCastTracerSPtr()
{
    return std::make_shared<RayCastTracer>();
}


