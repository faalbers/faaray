#include "PointArray.hpp"

PointArray::PointArray(const Size &dim, const Size &size)
    :   dataPtr_(new Scalar[(dim+1)*size]),
        dim_(dim),
        size_(size)
{
}

PointArray::~PointArray()
{
   delete[] dataPtr_;
}

const Size & PointArray::dim() const
{
    return dim_;
}

const Size & PointArray::size() const
{
    return size_;
}

