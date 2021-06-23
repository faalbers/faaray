#include "MultiJitteredSampler.hpp"

MultiJitteredSampler::MultiJitteredSampler()
    :   Sampler()
{
    generateSamples();
}

MultiJitteredSampler::MultiJitteredSampler(const GFA::Size &numSamplesRef)
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
    for (GFA::Index p = 0; p < numSets_; p++) {
        for (GFA::Index j = 0; j < numOneDimSamples_; j++) {
            for (GFA::Index k = 0; k < numOneDimSamples_; k++) {
                GFA::Point2D sp(
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
    const GFA::Size &numSamplesRef)
{
    return std::make_shared<MultiJitteredSampler>(numSamplesRef);
}


