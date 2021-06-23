#ifndef __FAARAY_LAMBERTIANBRDF_H__
#define __FAARAY_LAMBERTIANBRDF_H__

#include "Shared/Shared.hpp"

#include "BRDF.hpp"

class LambertianBRDF : public BRDF
{
public:
    LambertianBRDF();
    virtual ~LambertianBRDF();

    void setCd(
        const GFA::Scalar &r,
        const GFA::Scalar &g,
        const GFA::Scalar &b);
    void setKd(const GFA::Scalar &kd);
        
    const GFA::RGBColor & getCd() const;
    
    virtual void rho(TraceThread &ttRef) const;
    virtual void f(TraceThread &ttRef) const;
    
private:
    GFA::RGBColor   cd_;    // diffuse color
    GFA::Scalar     kd_;    // Diffuse Reflection Coefficient
};

#endif

