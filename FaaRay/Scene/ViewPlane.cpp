
#include "Scene/ViewPlane.hpp"
#include "Samplers/Sampler.hpp"
#include "Samplers/RegularSampler.hpp"
#include "Samplers/MultiJitteredSampler.hpp"

ViewPlane::ViewPlane()
    :   frameBufferPtr_(new RGBColorBuffer),
        pixelSize_(1.0),
        samplerSPtr_(new RegularSampler)
{
}

ViewPlane::ViewPlane(const Size width, const Size height)
    :   frameBufferPtr_(new RGBColorBuffer(width, height)),
        pixelSize_(10.0/256.0),
        samplerSPtr_(new RegularSampler(1))
{
}

ViewPlane::~ViewPlane(void)
{
    delete frameBufferPtr_;
}

const Size & ViewPlane::width() const
{
    return frameBufferPtr_->width();
}

const Size & ViewPlane::height() const
{
    return frameBufferPtr_->height();
}

const Scalar & ViewPlane::pixelSize() const
{
    return pixelSize_;
}

const Size & ViewPlane::numSamples() const
{
    return samplerSPtr_->numSamples();
}

void ViewPlane::setPixel(
    const Index &x, const Index &y,
    const RGBColor &col) const
{
    frameBufferPtr_->setPixel(x, y, col);
    setGUIPixel_(x, y, col);
}

void ViewPlane::setNumSamples(const Size &numSamples)
{
    if (samplerSPtr_->numSamples() == numSamples) return;

    // no need to reset prior samplerSPtr, this happens automatically
    if (numSamples > 1) samplerSPtr_ = MakeMultiJitteredSamplerSPtr(numSamples);
    else samplerSPtr_ = MakeRegularSamplerSPtr(numSamples);
}

const Sampler * ViewPlane::getSamplerPtr() const
{
    return samplerSPtr_.get();
}

SamplerSPtr ViewPlane::getSamplerSPtr() const
{
    return samplerSPtr_;
}

ConstSamplerSPtr ViewPlane::getConstSamplerSPtr() const
{
    return samplerSPtr_;
}

void ViewPlane::setGUIPixel_(const Index &, const Index &,
        const RGBColor &) const
{
}


