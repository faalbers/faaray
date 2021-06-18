
#include "Point2D.hpp"

Point2D::Point2D()
    :   x(0.0),
        y(0.0)
{
}

Point2D::Point2D(const Scalar &x_, const Scalar &y_)
    :   x(x_),
        y(y_)
{
}

std::ostream & operator<< (std::ostream &os, Point2D const &rhs)
{
    os << "Point2D(" << rhs.x << ", " << rhs.y << ")";
    return os;
}


