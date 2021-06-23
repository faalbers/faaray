
#include "Vector/Vector3D.hpp"
#include <math.h>
#include "Normal.hpp"

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

void GFA::Vector3D::normalize()
{
    GFA::Scalar dom = 1.0 / sqrt(x*x + y*y + z*z);
    x *= dom;
    y *= dom;
    z *= dom;
}

GFA::Vector3D GFA::Vector3D::operator+ (const GFA::Vector3D &rhs) const
{
    return GFA::Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

GFA::Vector3D GFA::Vector3D::operator- (const GFA::Vector3D &rhs) const
{
    return GFA::Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

GFA::Vector3D GFA::Vector3D::operator* (const GFA::Scalar &rhs) const
{
    return GFA::Vector3D(x * rhs, y * rhs, z * rhs);
}

GFA::Vector3D GFA::Vector3D::operator/ (const GFA::Scalar &rhs) const
{
    return GFA::Vector3D(x / rhs, y / rhs, z / rhs);
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

// dot product
GFA::Scalar GFA::Vector3D::operator* (const GFA::Normal &rhs) const
{
    return x*rhs.x+y*rhs.y+z*rhs.z;
}

std::ostream & operator<< (std::ostream &os, const GFA::Vector3D &rhs)
{
    os << "Vector3D(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}


