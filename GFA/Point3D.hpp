
#ifndef __GFA_POINT3D_H__
#define __GFA_POINT3D_H__

#include "GFA.hpp"
#include <iostream>


class Vector3D;

class Point3D
{
    public:
        Point3D();
        Point3D(const Scalar &x_, const Scalar &y_, const Scalar &z_);

        Scalar x, y, z;
        
        Vector3D    operator-(const Point3D &rhs) const;
        Point3D     operator+(const Vector3D& rhs) const;
};

std::ostream & operator<< (std::ostream &os, Point3D const &rhs);

#endif


