#ifndef __FAARAY_BRDF_H__
#define __FAARAY_BRDF_H__

namespace FaaRay {

class TraceThread;

class BRDF
{
    public:
        BRDF();
        virtual ~BRDF();
        
        virtual void rho(FaaRay::TraceThread &ttRef) const = 0;
        virtual void f(FaaRay::TraceThread &ttRef) const = 0;
};

}

#endif

