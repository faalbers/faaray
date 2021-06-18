#ifndef __GFA_MATRIX_H__
#define __GFA_MATRIX_H__

#include "GFA.hpp"

class Matrix
{
    public:
        Matrix(const Size &cols, const Size &rows);
        ~Matrix();
    
        const Size & columns() const;
        const Size & rows() const;
    private:
        Scalar  *dataPtr_;
        Size    cols_;
        Size    rows_;
};

#endif

