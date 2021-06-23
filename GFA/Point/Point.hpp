#ifndef __GFA_POINT_H__
#define __GFA_POINT_H__

#include "Shared/Shared.hpp"

namespace GFA {
class Point
{
    public:
        Point();
        Point(const Point &pointRef);
        Point(const Size &dim);
        ~Point();
    
        const Size & dim() const;

        Scalar &        operator[](const Index &col);
        const Scalar &  operator[](const Index &col) const;
        Point &         operator=(const Point &rhs);

        Scalar  *dataPtr_;
    protected:
        Size    dim_;
};

}

#endif


