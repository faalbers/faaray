
#ifndef __FAARAY_TRACER_H__
#define __FAARAY_TRACER_H__

#include <memory>
#include "Utils/FaaRay.hpp"

class TraceThread;

class Tracer
{
    public:
        Tracer();
        virtual ~Tracer(void);
        
        virtual void traceRay(TraceThread &ttRef) const = 0;
};
                                  
typedef std::shared_ptr<Tracer> TracerSPtr;
typedef std::shared_ptr<const Tracer> ConstTracerSPtr;

#endif


