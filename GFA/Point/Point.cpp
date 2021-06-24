#include "Point/Point.hpp"
#include "Shared/Shared.hpp"

GFA::Point::Point()
    : dataPtr_(0)
    , dim_(0)
{
    
}

GFA::Point::Point(const GFA::Point &pointRef)
    :   dataPtr_(0),
        dim_(pointRef.dim_)
{
    if (dim_ == 0) return;
    dataPtr_ = new GFA::Scalar[dim_];
    for (GFA::Index i = 0; i < dim_; i++) dataPtr_[i] = pointRef.dataPtr_[i];
}

GFA::Point::Point(const GFA::Size &dim)
    :   dataPtr_(new GFA::Scalar[dim+1]),
        dim_(dim)
{
    // last value is 1.0 for proper matrix product
    dataPtr_[dim_] = 1.0;
}

GFA::Point::~Point()
{
   delete[] dataPtr_;
}

const GFA::Size & GFA::Point::dim() const
{
    return dim_;
}

GFA::Scalar & GFA::Point::operator[](const GFA::Index &col)
{
    return dataPtr_[col];
}

const GFA::Scalar & GFA::Point::operator[](const GFA::Index &col) const
{
    return dataPtr_[col];
}

GFA::Point & GFA::Point::operator=(const GFA::Point& rhs)
{
    if (dim_ != rhs.dim_) {
        if (dataPtr_ != 0) {
            delete[] dataPtr_;
            dataPtr_ = 0;
        }
        dataPtr_ = new GFA::Scalar[rhs.dim_];
        dim_ = rhs.dim_;
    }

    for (GFA::Index i = 0; i < dim_; i++) dataPtr_[i] = rhs.dataPtr_[i];
    
    return *this;
}

