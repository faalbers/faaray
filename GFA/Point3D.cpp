
#include "Point3D.hpp"
#include "Vector3D.hpp"

Point3D::Point3D()
    :   x(0.0),
        y(0.0),
        z(0.0)
{
}

Point3D::Point3D(const Scalar &x_, const Scalar &y_, const Scalar &z_)
    :   x(x_),
        y(y_),
        z(z_)
{
}

Vector3D Point3D::operator-(const Point3D &rhs) const
{
    Vector3D temp;
    temp.x = x-rhs.x;
    temp.y = y-rhs.y;
    temp.z = z-rhs.z;
    return temp;
}

Point3D Point3D::operator+(const Vector3D& rhs) const
{
    Point3D temp;
    temp.x = x+rhs.x;
    temp.y = y+rhs.y;
    temp.z = z+rhs.z;
    return temp;
}

std::ostream & operator<< (std::ostream &os, Point3D const &rhs)
{
    os << "Point3D(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}


