
#include "Point2D.hpp"
#include "Shared/Shared.hpp"

GFA::Point2D::Point2D()
    :   x(0.0),
        y(0.0)
{
}

GFA::Point2D::Point2D(const GFA::Scalar &x_, const GFA::Scalar &y_)
    :   x(x_),
        y(y_)
{
}

std::ostream & GFA::operator<< (std::ostream &os, GFA::Point2D const &rhs)
{
    os << "Point2D(" << rhs.x << ", " << rhs.y << ")";
    return os;
}


