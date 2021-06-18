
#include "Vector3D.hpp"
#include <math.h>
#include "Normal.hpp"

Vector3D::Vector3D()
    :   x(0.0),
        y(0.0),
        z(0.0)
{
}

Vector3D::Vector3D(const Scalar &x_, const Scalar &y_, const Scalar &z_)
    :   x(x_),
        y(y_),
        z(z_)
{
}

void Vector3D::normalize()
{
    Scalar dom = 1.0 / sqrt(x*x + y*y + z*z);
    x *= dom;
    y *= dom;
    z *= dom;
}

Vector3D Vector3D::operator+ (const Vector3D &rhs) const
{
    return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3D Vector3D::operator- (const Vector3D &rhs) const
{
    return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3D Vector3D::operator* (const Scalar &rhs) const
{
    return Vector3D(x * rhs, y * rhs, z * rhs);
}

Vector3D Vector3D::operator/ (const Scalar &rhs) const
{
    return Vector3D(x / rhs, y / rhs, z / rhs);
}

// cross product
Vector3D Vector3D::operator^ (const Vector3D& rhs) const
{
    return Vector3D(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

// dot product
Scalar Vector3D::operator* (const Vector3D &rhs) const
{
    return x*rhs.x+y*rhs.y+z*rhs.z;
}

// dot product
Scalar Vector3D::operator* (const Normal &rhs) const
{
    return x*rhs.x+y*rhs.y+z*rhs.z;
}

std::ostream & operator<< (std::ostream &os, const Vector3D &rhs)
{
    os << "Vector3D(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}


