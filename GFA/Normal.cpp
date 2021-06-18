
#include "Normal.hpp"
#include "Vector3D.hpp"

Normal::Normal()
    :   x(0.0),
        y(0.0),
        z(0.0)
{
}

Normal::Normal(const Scalar &x_, const Scalar &y_, const Scalar &z_)
    :   x(x_),
        y(y_),
        z(z_)
{
}

Normal & Normal::operator= (const Vector3D &rhs)
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

// dot product
Scalar Normal::operator* (const Normal &rhs) const
{
    return x*rhs.x+y*rhs.y+z*rhs.z;
}


