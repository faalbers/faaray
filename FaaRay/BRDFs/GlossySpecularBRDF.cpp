#include "BRDFs/GlossySpecularBRDF.hpp"
#include "Render/TraceThread.hpp"

FaaRay::GlossySpecularBRDF::GlossySpecularBRDF()
    : kd_(1.0)
    , cd_(GFA::RGBColor(1.0, 1.0, 1.0))
{
}

FaaRay::GlossySpecularBRDF::~GlossySpecularBRDF()
{
}

// diffuse color
void FaaRay::GlossySpecularBRDF::setCd(
    const GFA::Scalar &r,
    const GFA::Scalar &g,
    const GFA::Scalar &b)
{
    cd_.r = r; cd_.g = g; cd_.b = b;
}

// Diffuse Reflection Coefficient
void FaaRay::GlossySpecularBRDF::setKd(const GFA::Scalar &kd)
{
    kd_ = kd;
}

const GFA::RGBColor & FaaRay::GlossySpecularBRDF::getCd() const
{
    return cd_;
}

GFA::RGBColor FaaRay::GlossySpecularBRDF::rho(FaaRay::TraceThread &ttRef) const
{
    return (cd_*kd_);
}

void FaaRay::GlossySpecularBRDF::f(FaaRay::TraceThread &ttRef) const
{
    ttRef.srFColor = cd_ * kd_ * GFA::invPI;
}
