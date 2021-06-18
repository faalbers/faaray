#include "Point.hpp"

Point::Point()
    :   dataPtr_(0),
        dim_(0)
{
}

Point::Point(const Point &pointRef)
    :   dataPtr_(0),
        dim_(pointRef.dim_)
{
    if (dim_ == 0) return;
    dataPtr_ = new Scalar[dim_];
    for (Index i = 0; i < dim_; i++) dataPtr_[i] = pointRef.dataPtr_[i];
}

Point::Point(const Size &dim)
    :   dataPtr_(new Scalar[dim+1]),
        dim_(dim)
{
    // last value is 1.0 for proper matrix product
    dataPtr_[dim_] = 1.0;
}

Point::~Point()
{
   delete[] dataPtr_;
}

const Size & Point::dim() const
{
    return dim_;
}

Scalar & Point::operator[](const Index &col)
{
    return dataPtr_[col];
}

const Scalar & Point::operator[](const Index &col) const
{
    return dataPtr_[col];
}

Point & Point::operator=(const Point& rhs)
{
    if (dim_ != rhs.dim_) {
        if (dataPtr_ != 0) {
            delete[] dataPtr_;
            dataPtr_ = 0;
        }
        dataPtr_ = new Scalar[rhs.dim_];
        dim_ = rhs.dim_;
    }

    for (Index i = 0; i < dim_; i++) dataPtr_[i] = rhs.dataPtr_[i];
    
    return *this;
}

