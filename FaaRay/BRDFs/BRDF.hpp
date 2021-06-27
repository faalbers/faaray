#ifndef __FAARAY_BRDF_H__
#define __FAARAY_BRDF_H__

#include "GFA.hpp"

namespace FaaRay {

class TraceThread;

class BRDF
{
    public:
        BRDF();
        virtual ~BRDF();
        
        virtual GFA::RGBColor rho(FaaRay::TraceThread &ttRef) const = 0;
        virtual GFA::RGBColor f(FaaRay::TraceThread &ttRef) const = 0;
};

}

#endif

