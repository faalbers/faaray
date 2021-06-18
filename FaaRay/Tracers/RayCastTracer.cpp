
#include "RayCastTracer.hpp"
#include "Render/TraceThread.hpp"
#include "Scene/Scene.hpp"
#include "Materials/Material.hpp"

RayCastTracer::~RayCastTracer()
{
}

void RayCastTracer::traceRay(TraceThread &ttRef) const
{
    ttRef.sceneSPtr->hitObjects(ttRef);
    if(ttRef.srHitAnObject) {
        ttRef.srMaterialSPtr->shade(ttRef);
    } else {
        ttRef.srColor.r = 0.0; ttRef.srColor.g = 0.0; ttRef.srColor.b = 0.0;
        ttRef.srColor.a = 0.0;
    }
}

RayCastTracerSPtr MakeRayCastTracerSPtr()
{
    return std::make_shared<RayCastTracer>();
}


