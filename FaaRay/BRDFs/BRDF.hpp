#ifndef __FAARAY_BRDF_H__
#define __FAARAY_BRDF_H__

#include "GFA.hpp"
#include "RGBColor.hpp"

class TraceThread;

class BRDF
{
    public:
        BRDF();
        virtual ~BRDF();
        
        virtual void rho(TraceThread &ttRef) const = 0;
        virtual void f(TraceThread &ttRef) const = 0;
};

#endif

