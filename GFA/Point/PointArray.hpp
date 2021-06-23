#ifndef __GFA_POINTARRAY_H__
#define __GFA_POINTARRAY_H__

#include "Shared/Shared.hpp"

namespace GFA {
class PointArray
{
    public:
        PointArray(const Size &dim, const Size &size);
        ~PointArray();
    
        const Size & dim() const;
        const Size & size() const;
    private:
        Scalar  *dataPtr_;
        Size    dim_;
        Size    size_;
};

}

#endif

