#include "VectorArray.hpp"
#include "Shared/Shared.hpp"

GFA::VectorArray::VectorArray(const GFA::Size &dim, const GFA::Size &size)
    :   dataPtr_(new GFA::Scalar[(dim+1)*size]),
        dim_(dim),
        size_(size)
{
}

GFA::VectorArray::~VectorArray()
{
   delete[] dataPtr_;
}

const GFA::Size & GFA::VectorArray::dim() const
{
    return dim_;
}

const GFA::Size & GFA::VectorArray::size() const
{
    return size_;
}

