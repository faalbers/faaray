
#ifndef __GFA_VECTOR3D_H__
#define __GFA_VECTOR3D_H__

#include "Shared/Shared.hpp"
#include <iostream>

namespace GFA {

class Vector3D
{
    public:
        Vector3D();
        Vector3D(const GFA::Scalar &x_, const GFA::Scalar &y_, const GFA::Scalar &z_);

        GFA::Scalar x, y, z;
        
        void normalize();
        Vector3D normal();
        
        Vector3D operator+ (const Vector3D &rhs) const;
        Vector3D operator- (const Vector3D &rhs) const;
        Vector3D operator* (const GFA::Scalar &rhs) const;
        Vector3D &operator*=(const GFA::Scalar &rhs);
        Vector3D operator/ (const GFA::Scalar &rhs) const;
        Vector3D &operator/=(const GFA::Scalar &rhs);
        
        // cross product
        Vector3D operator^ (const Vector3D &rhs) const;
        // dot product
        GFA::Scalar operator* (const Vector3D &rhs) const;

};

std::ostream & operator<< (std::ostream &os, const Vector3D &rhs);

}

#endif


