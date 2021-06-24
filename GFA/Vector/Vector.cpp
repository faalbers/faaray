#include "Vector.hpp"
#include "Shared/Shared.hpp"

GFA::Vector::Vector()
    :   dataPtr_(0),
        dim_(0)
{
}

GFA::Vector::Vector(const GFA::Vector &vectorRef)
    :   dataPtr_(0),
        dim_(vectorRef.dim_)
{
    if (dim_ == 0) return;
    dataPtr_ = new GFA::Scalar[dim_];
    for (GFA::Index i = 0; i < dim_; i++) dataPtr_[i] = vectorRef.dataPtr_[i];
}

GFA::Vector::Vector(const GFA::Size &dim)
    :   dataPtr_(new GFA::Scalar[dim+1]),
        dim_(dim)
{
    // last value is 1.0 for proper matrix product
    dataPtr_[dim_] = 1.0;
}

GFA::Vector::~Vector()
{
   delete[] dataPtr_;
}

const GFA::Size & GFA::Vector::dim() const
{
    return dim_;
}

GFA::Scalar & GFA::Vector::operator[](const GFA::Index &col)
{
    return dataPtr_[col];
}

const GFA::Scalar & GFA::Vector::operator[](const GFA::Index &col) const
{
    return dataPtr_[col];
}

GFA::Vector & GFA::Vector::operator=(const GFA::Vector& rhs)
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

