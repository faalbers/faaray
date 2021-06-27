
#include "Normal.hpp"
#include "Shared/Shared.hpp"
#include "Vector/Vector3D.hpp"

GFA::Normal::Normal()
{
}

GFA::Normal::Normal(const GFA::Scalar &x_, const GFA::Scalar &y_, const GFA::Scalar &z_)
    : GFA::Vector3D(x_, y_, z_)
{
    normalize();
}

GFA::Normal::Normal(const Vector3D &v)
{
    x = v.x; y = v.y; z = v.z;
    normalize();
}

GFA::Normal &GFA::Normal::operator*=(const GFA::Scalar &rhs)
{
    return *this;
}

GFA::Normal &GFA::Normal::operator/=(const GFA::Scalar &rhs)
{
    return *this;
}

std::ostream & GFA::operator<< (std::ostream &os, const GFA::Normal &rhs)
{
    os << "Normal(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}
