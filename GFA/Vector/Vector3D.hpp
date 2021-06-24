
#ifndef __GFA_VECTOR3D_H__
#define __GFA_VECTOR3D_H__

#include "Shared/Shared.hpp"
#include "Normal.hpp"
#include <iostream>


namespace GFA {

class Vector3D
{
    public:
        Vector3D();
        Vector3D(const Scalar &x_, const Scalar &y_, const Scalar &z_);

        Scalar x, y, z;
        
        void normalize();
        
        Vector3D operator+ (const Vector3D &rhs) const;
        Vector3D operator- (const Vector3D &rhs) const;
        Vector3D operator* (const Scalar &rhs) const;
        Vector3D operator/ (const Scalar &rhs) const;
        
        // cross product
        Vector3D operator^ (const Vector3D &rhs) const;
        // dot product
        Scalar operator* (const Vector3D &rhs) const;
        Scalar operator* (const Normal &rhs) const;

};

std::ostream & operator<< (std::ostream &os, const Vector3D &rhs);

}

#endif


