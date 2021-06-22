#ifndef __FAARAY_RAYCASTTRACER_H__
#define __FAARAY_RAYCASTTRACER_H__

#include "Shared/Shared.hpp"
#include <memory>
#include "Tracer.hpp"

class RayCastTracer : public Tracer
{
    public:
        RayCastTracer();
        ~RayCastTracer();

        virtual void traceRay(TraceThread &ttRef) const;
};
                                  
typedef std::shared_ptr<RayCastTracer>  RayCastTracerSPtr;
RayCastTracerSPtr MakeRayCastTracerSPtr();

#endif


