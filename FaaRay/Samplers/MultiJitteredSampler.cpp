#include "Samplers/MultiJitteredSampler.hpp"

MultiJitteredSampler::MultiJitteredSampler()
    :   Sampler()
{
    generateSamples();
}

MultiJitteredSampler::MultiJitteredSampler(const Size &numSamplesRef)
    :   Sampler(numSamplesRef)
{
    generateSamples();
}

MultiJitteredSampler::~MultiJitteredSampler()
{
}

void MultiJitteredSampler::generateSamples(void)
{
    // Create numSets of numOneDimSamples by numOneDimSamples random box
    // points between 0.0 and less then 1.0
    for (Index p = 0; p < numSets_; p++) {
        for (Index j = 0; j < numOneDimSamples_; j++) {
            for (Index k = 0; k < numOneDimSamples_; k++) {
                Point2D sp(
                    (k + rand_()) / numOneDimSamples_,         
                    (j + rand_()) / numOneDimSamples_);
                samples_.push_back(sp);
            }
        }
    }
}

MultiJitteredSamplerSPtr MakeMultiJitteredSamplerSPtr()
{
    return std::make_shared<MultiJitteredSampler>();
}

MultiJitteredSamplerSPtr MakeMultiJitteredSamplerSPtr(
    const Size &numSamplesRef)
{
    return std::make_shared<MultiJitteredSampler>(numSamplesRef);
}


