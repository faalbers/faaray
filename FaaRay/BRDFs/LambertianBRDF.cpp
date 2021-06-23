#include "BRDFs/LambertianBRDF.hpp"

#include "Render/TraceThread.hpp"

LambertianBRDF::LambertianBRDF()
    : kd_(1.0)
    , cd_(GFA::RGBColor(1.0, 1.0, 1.0))
{
}

LambertianBRDF::~LambertianBRDF()
{
}

// diffuse color
void LambertianBRDF::setCd(
    const GFA::Scalar &r,
    const GFA::Scalar &g,
    const GFA::Scalar &b)
{
    cd_.r = r; cd_.g = g; cd_.b = b;
}

// Diffuse Reflection Coefficient
void LambertianBRDF::setKd(const GFA::Scalar &kd)
{
    kd_ = kd;
}

const GFA::RGBColor & LambertianBRDF::getCd() const
{
    return cd_;
}

void LambertianBRDF::rho(TraceThread &ttRef) const
{
    ttRef.srRhoColor = cd_*kd_;
}

void LambertianBRDF::f(TraceThread &ttRef) const
{
    ttRef.srFColor = cd_ * kd_ * GFA::invPI;
}
