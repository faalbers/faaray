#include "Matrix.hpp"
#include "Shared/Shared.hpp"

GFA::Matrix::Matrix(const GFA::Size &cols, const GFA::Size &rows)
    :   dataPtr_(new GFA::Scalar[cols*rows]),
        cols_(cols),
        rows_(rows)
{
}

GFA::Matrix::~Matrix()
{
   delete[] dataPtr_;
}

const GFA::Size & GFA::Matrix::columns() const
{
    return cols_;
}

const GFA::Size & GFA::Matrix::rows() const
{
    return rows_;
}

