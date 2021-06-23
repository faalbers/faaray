#ifndef __GFA_POINT2D_H__
#define __GFA_POINT2D_H__

#include "Shared/Shared.hpp"
#include <iostream>

namespace GFA {
class Point2D
{
    public:
        Point2D();
        Point2D(const Scalar &x_, const Scalar &y_);
        
        Scalar x, y;
};

std::ostream & operator<< (std::ostream &os, Point2D const &rhs);

}

#endif

