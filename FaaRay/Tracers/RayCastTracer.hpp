#ifndef __FAARAY_RAYCASTTRACER_H__
#define __FAARAY_RAYCASTTRACER_H__

#include <memory>
#include "Utils/FaaRay.hpp"
#include "Tracers/Tracer.hpp"

class RayCastTracer : public Tracer
{
    public:
        virtual ~RayCastTracer(void);

        virtual void traceRay(TraceThread &ttRef) const;
};
                                  
typedef std::shared_ptr<RayCastTracer>  RayCastTracerSPtr;
RayCastTracerSPtr MakeRayCastTracerSPtr();

#endif


