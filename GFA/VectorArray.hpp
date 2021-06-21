#ifndef __GFA_VECTORARRAY_H__
#define __GFA_VECTORARRAY_H__

#include "Shared.hpp"

class VectorArray
{
    public:
        VectorArray(const Size &dim, const Size &size);
        ~VectorArray();
    
        const Size & dim() const;
        const Size & size() const;
    private:
        Scalar  *dataPtr_;
        Size    dim_;
        Size    size_;
};

#endif

