
#include "ViewPlane.hpp"
#include "Samplers/Sampler.hpp"
#include "Samplers/RegularSampler.hpp"
#include "Samplers/MultiJitteredSampler.hpp"

ViewPlane::ViewPlane()
    :   frameBufferPtr_(new GFA::RGBColorBuffer),
        pixelSize_(1.0),
        samplerSPtr_(new RegularSampler)
{
    constructDebug("ViewPlane");
}

// NeedFix: Is this called at all ?S
ViewPlane::ViewPlane(const GFA::Size width, const GFA::Size height)
    :   frameBufferPtr_(new GFA::RGBColorBuffer(width, height)),
        pixelSize_(10.0/256.0),
        samplerSPtr_(new RegularSampler(1))
{
    constructDebug("ViewPlane");
}

ViewPlane::~ViewPlane(void)
{
    delete frameBufferPtr_;
    sPtrDebug("ViewPlane:samplerSPtr_", samplerSPtr_);
    deconstructDebug("ViewPlane");
}

const GFA::Size & ViewPlane::width() const
{
    return frameBufferPtr_->width();
}

const GFA::Size & ViewPlane::height() const
{
    return frameBufferPtr_->height();
}

const GFA::Scalar & ViewPlane::pixelSize() const
{
    return pixelSize_;
}

const GFA::Size & ViewPlane::numSamples() const
{
    return samplerSPtr_->numSamples();
}

// NeedFix: are we setting 2 buffers ??
void ViewPlane::setPixel(
    const GFA::Index &x, const GFA::Index &y,
    const GFA::RGBColor &col) const
{
    // NeedFix: frameBufferPtr does not do anything right now
    frameBufferPtr_->setPixel(x, y, col);
    setGUIPixel_(x, y, col);
}

void ViewPlane::setNumSamples(const GFA::Size &numSamples)
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

// NeedFix: why to procs doing the same thing
SamplerSPtr ViewPlane::getSamplerSPtr() const
{
    return samplerSPtr_;
}

ConstSamplerSPtr ViewPlane::getConstSamplerSPtr() const
{
    return samplerSPtr_;
}

void ViewPlane::setGUIPixel_(const GFA::Index &, const GFA::Index &,
        const GFA::RGBColor &) const
{
}


