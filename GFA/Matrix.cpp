#include "Matrix.hpp"

Matrix::Matrix(const Size &cols, const Size &rows)
    :   dataPtr_(new Scalar[cols*rows]),
        cols_(cols),
        rows_(rows)
{
}

Matrix::~Matrix()
{
   delete[] dataPtr_;
}

const Size & Matrix::columns() const
{
    return cols_;
}

const Size & Matrix::rows() const
{
    return rows_;
}

