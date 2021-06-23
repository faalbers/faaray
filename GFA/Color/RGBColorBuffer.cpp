
#include "RGBColorBuffer.hpp"
#include "RGBColor.hpp"

GFA::RGBColorBuffer::RGBColorBuffer()
    :   width_(0),
        height_(0),
        size_(0),
        dataPtr_(0)
{
}

GFA::RGBColorBuffer::RGBColorBuffer(const GFA::Size &width, const GFA::Size &height)
    :   width_(width),
        height_(height),
        size_((width_*4)*height_),
        dataPtr_(new GFA::Scalar[size_])
{
}

GFA::RGBColorBuffer::~RGBColorBuffer()
{
   if (dataPtr_ != 0) delete[] dataPtr_;
}

const GFA::Size & GFA::RGBColorBuffer::width() const
{
    return width_;
}

const GFA::Size & GFA::RGBColorBuffer::height() const
{
    return height_;
}

void GFA::RGBColorBuffer::setPixel(
    const GFA::Index &, const GFA::Index &, const GFA::RGBColor &)
{
    // NeedFis: Dees to be set up
}


