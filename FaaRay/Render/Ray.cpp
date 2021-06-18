#include "Ray.hpp"

Ray::Ray()
{
}

Ray::Ray(const Ray &rayRef)
    :   origin_(rayRef.origin_),
        direction_(rayRef.direction_)
{
}

Ray::Ray(const Point3D &originRef, const Vector3D &directionRef)
    :   origin_(originRef),
        direction_(directionRef)
{
}

void Ray::setOrigin(const Point3D &originRef)
{
    origin_ = originRef;
}


