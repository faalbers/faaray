
#include "Point3D.hpp"
#include "Vector/Vector3D.hpp"

GFA::Point3D::Point3D()
    :   x(0.0),
        y(0.0),
        z(0.0)
{
}

GFA::Point3D::Point3D(const GFA::Scalar &x_, const GFA::Scalar &y_, const GFA::Scalar &z_)
    :   x(x_),
        y(y_),
        z(z_)
{
}

GFA::Vector3D GFA::Point3D::operator-(const GFA::Point3D &rhs) const
{
    GFA::Vector3D temp;
    temp.x = x-rhs.x;
    temp.y = y-rhs.y;
    temp.z = z-rhs.z;
    return temp;
}

GFA::Point3D GFA::Point3D::operator+(const GFA::Vector3D& rhs) const
{
    GFA::Point3D temp;
    temp.x = x+rhs.x;
    temp.y = y+rhs.y;
    temp.z = z+rhs.z;
    return temp;
}

std::ostream & operator<< (std::ostream &os, GFA::Point3D const &rhs)
{
    os << "Point3D(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}


