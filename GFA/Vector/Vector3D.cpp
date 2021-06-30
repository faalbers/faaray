
#include "Vector3D.hpp"
#include "Shared/Shared.hpp"
#include <iostream>
#include <math.h>

GFA::Vector3D::Vector3D()
    :   x(0.0),
        y(0.0),
        z(0.0)
{
}

GFA::Vector3D::Vector3D(const GFA::Scalar &x_, const GFA::Scalar &y_, const GFA::Scalar &z_)
    :   x(x_),
        y(y_),
        z(z_)
{
}

GFA::Scalar GFA::Vector3D::length()
{
    return (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

void GFA::Vector3D::normalize()
{
    GFA::Scalar dom = 1.0 / sqrt(x*x + y*y + z*z);
    x *= dom;
    y *= dom;
    z *= dom;
    if ( isnan(x) ) x = 0;
    if ( isnan(y) ) y = 0;
    if ( isnan(z) ) z = 0;
}

GFA::Vector3D GFA::Vector3D::normal()
{
    GFA::Vector3D hello = *this;
    hello.normalize();
    return hello;
}

GFA::Vector3D GFA::Vector3D::operator+ (const GFA::Vector3D &rhs) const
{
    return GFA::Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

GFA::Vector3D GFA::Vector3D::operator- (const GFA::Vector3D &rhs) const
{
    return GFA::Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

GFA::Vector3D GFA::Vector3D::operator- () const
{
    return GFA::Vector3D(-x, -y, -z);
}

GFA::Vector3D GFA::Vector3D::operator* (const GFA::Scalar &rhs) const
{
    return GFA::Vector3D(x * rhs, y * rhs, z * rhs);
}

GFA::Vector3D &GFA::Vector3D::operator*=(const GFA::Scalar &rhs)
{
    x *= rhs; y *= rhs; z *= rhs; 
    return *this;
}

GFA::Vector3D GFA::Vector3D::operator/ (const GFA::Scalar &rhs) const
{
    return GFA::Vector3D(x / rhs, y / rhs, z / rhs);
}

GFA::Vector3D &GFA::Vector3D::operator/=(const GFA::Scalar &rhs)
{
    x /= rhs; y /= rhs; z /= rhs; 
    return *this;
}

// cross product
GFA::Vector3D GFA::Vector3D::operator^ (const GFA::Vector3D& rhs) const
{
    return GFA::Vector3D(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

// dot product
GFA::Scalar GFA::Vector3D::operator* (const GFA::Vector3D &rhs) const
{
    return x*rhs.x+y*rhs.y+z*rhs.z;
}

std::ostream & GFA::operator<< (std::ostream &os, const GFA::Vector3D &rhs)
{
    os << "Vector3D(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}
