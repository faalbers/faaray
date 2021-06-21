#include "AmbientLight.hpp"
#include "Render/TraceThread.hpp"

AmbientLight::AmbientLight()
    :   ls_(1.0),
        color_(RGBColor(1.0, 1.0, 1.0))
{
    constructDebug("AmbientLight");
}

AmbientLight::~AmbientLight()
{
    deconstructDebug("AmbientLight");
}

void AmbientLight::setLs(const Scalar &ls)
{
    ls_ = ls;
}

void  AmbientLight::getDirection(TraceThread &ttRef) const
{
    ttRef.lDirection = Vector3D(0.0, 0.0, 0.0);
}

void  AmbientLight::inShadow(TraceThread &ttRef) const
{
    ttRef.sRayInShadow = false;
}

void  AmbientLight::L(TraceThread &ttRef) const
{
    ttRef.srAmbientL = color_ * ls_;
}

AmbientLightSPtr MakeAmbientLightSPtr()
{
    return std::make_shared<AmbientLight>();
}


