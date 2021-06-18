#include "PointLight.hpp"
#include "Render/TraceThread.hpp"

PointLight::PointLight()
    :   ls_(1.0),
        color_(RGBColor(1.0, 1.0, 1.0))
{
}

PointLight::~PointLight()
{
}

void PointLight::setCenter(
    const Scalar &x,
    const Scalar &y,
    const Scalar &z)
{
    center_.x = x;
    center_.y = y;
    center_.z = z;
}

void  PointLight::getDirection(TraceThread &ttRef) const
{
    ttRef.lDirection = center_ - ttRef.srHitPoint;
    ttRef.lDirection.normalize();
}

void  PointLight::inShadow(TraceThread &ttRef) const
{
    if ( castsShadows() ) {
        ttRef.sRayInShadow = false;
    } else
        ttRef.sRayInShadow = false;
}

void  PointLight::L(TraceThread &ttRef) const
{
    ttRef.srLightL = color_ * ls_;
}

PointLightSPtr MakePointLightSPtr()
{
    return std::make_shared<PointLight>();
}

/*
    double t;
    int numObjects = sr.world.objects.size();
    double d = location.distance(ray.origin);

    for (int j = 0; j < numObjects; j++)
        if (sr.world.objects[j]->shadowHit(ray, t) && t < d)
            return true;
    
    return false;
*/
