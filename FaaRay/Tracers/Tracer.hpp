
#ifndef __FAARAY_TRACER_H__
#define __FAARAY_TRACER_H__

#include "Base/Base.hpp"

namespace FaaRay {

class TraceThread;

class Tracer : public Base
{
    public:
        Tracer();
        ~Tracer();
        
        virtual void traceRay(TraceThread &ttRef) const = 0;
};
                                  
typedef std::shared_ptr<Tracer> TracerSPtr;
typedef std::shared_ptr<const Tracer> ConstTracerSPtr;

}

#endif


