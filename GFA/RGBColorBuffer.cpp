
#include "RGBColorBuffer.hpp"
#include "RGBColor.hpp"

RGBColorBuffer::RGBColorBuffer()
    :   width_(0),
        height_(0),
        size_(0),
        dataPtr_(0)
{
}

RGBColorBuffer::RGBColorBuffer(const Size &width, const Size &height)
    :   width_(width),
        height_(height),
        size_((width_*4)*height_),
        dataPtr_(new Scalar[size_])
{
}

RGBColorBuffer::~RGBColorBuffer()
{
   if (dataPtr_ != 0) delete[] dataPtr_;
}

const Size & RGBColorBuffer::width() const
{
    return width_;
}

const Size & RGBColorBuffer::height() const
{
    return height_;
}

void RGBColorBuffer::setPixel(
    const Index &, const Index &, const RGBColor &)
{
    // NeedFis: Dees to be set up
}


