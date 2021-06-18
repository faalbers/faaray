#include "VectorArray.hpp"

VectorArray::VectorArray(const Size &dim, const Size &size)
    :   dataPtr_(new Scalar[(dim+1)*size]),
        dim_(dim),
        size_(size)
{
}

VectorArray::~VectorArray()
{
   delete[] dataPtr_;
}

const Size & VectorArray::dim() const
{
    return dim_;
}

const Size & VectorArray::size() const
{
    return size_;
}

