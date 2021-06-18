#ifndef __GFA_VECTOR_H__
#define __GFA_VECTOR_H__

#include "GFA.hpp"

class Vector
{
    public:
        Vector();
        Vector(const Vector &vectorRef);
        Vector(const Size &dim);
        ~Vector();
    
        const Size & dim() const;

        Scalar &        operator[](const Index &col);
        const Scalar &  operator[](const Index &col) const;
        Vector &        operator=(const Vector &rhs);

        Scalar  *dataPtr_;
    protected:
        Size    dim_;
};

#endif


