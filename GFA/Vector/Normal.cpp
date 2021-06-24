
#include "Normal.hpp"
#include "Shared/Shared.hpp"
#include "Vector/Vector3D.hpp"

GFA::Normal::Normal()
    :   x(0.0),
        y(0.0),
        z(0.0)
{
}

GFA::Normal::Normal(const GFA::Scalar &x_, const GFA::Scalar &y_, const GFA::Scalar &z_)
    :   x(x_),
        y(y_),
        z(z_)
{
}

GFA::Normal & GFA::Normal::operator= (const GFA::Vector3D &rhs)
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

// dot product
GFA::Scalar GFA::Normal::operator* (const GFA::Normal &rhs) const
{
    return x*rhs.x+y*rhs.y+z*rhs.z;
}


