#ifndef __FAARAY_GLOSSYSPECULARBRDF_H__
#define __FAARAY_GLOSSYSPECULARBRDF_H__

#include "BRDF.hpp"
#include "GFA.hpp"

namespace FaaRay {

class TraceThread;

class GlossySpecularBRDF : public FaaRay::BRDF
{
public:
    GlossySpecularBRDF();
    virtual ~GlossySpecularBRDF();

    void setCd(
        const GFA::Scalar &r,
        const GFA::Scalar &g,
        const GFA::Scalar &b);
    void setKd(const GFA::Scalar &kd);
        
    const GFA::RGBColor & getCd() const;
    
    virtual GFA::RGBColor rho(FaaRay::TraceThread &ttRef) const;
    virtual void f(FaaRay::TraceThread &ttRef) const;
    
private:
    GFA::RGBColor   cd_;    // diffuse color
    GFA::Scalar     kd_;    // Diffuse Reflection Coefficient
};

}

#endif

