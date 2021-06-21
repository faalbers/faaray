#ifndef __FAARAY_LAMBERTIANBRDF_H__
#define __FAARAY_LAMBERTIANBRDF_H__

#include "Shared.hpp"
#include "GFA.hpp"
#include "BRDF.hpp"

class LambertianBRDF : public BRDF
{
public:
    LambertianBRDF();
    virtual ~LambertianBRDF();

    void setCd(
        const Scalar &r,
        const Scalar &g,
        const Scalar &b);
    void setKd(const Scalar &kd);
        
    const RGBColor & getCd() const;
    
    virtual void rho(TraceThread &ttRef) const;
    virtual void f(TraceThread &ttRef) const;
    
private:
    RGBColor   cd_;    // diffuse color
    Scalar     kd_;    // Diffuse Reflection Coefficient
};

#endif

