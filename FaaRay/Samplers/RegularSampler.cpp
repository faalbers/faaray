#include "RegularSampler.hpp"

RegularSampler::RegularSampler()
    :   Sampler()
{
    generateSamples();
}

RegularSampler::RegularSampler(const GFA::Size &numSamplesRef)
    :   Sampler(numSamplesRef)
{
    generateSamples();
}

RegularSampler::~RegularSampler()
{
}

void RegularSampler::generateSamples()
{
    // Create numSets of numOneDimSamples by numOneDimSamples box
    // each point will be in the middle of each sample box area
    for (GFA::Index p = 0; p < numSets_; p++) {
        for (GFA::Index j = 0; j < numOneDimSamples_; j++) {
            for (GFA::Index k = 0; k < numOneDimSamples_; k++) {
                GFA::Point2D sp(
                    (k + 0.5) / numOneDimSamples_,
                    (j + 0.5) / numOneDimSamples_);
                samples_.push_back(sp);
            }
        }
    }
}

RegularSamplerSPtr MakeRegularSamplerSPtr()
{
    return std::make_shared<RegularSampler>();
}

RegularSamplerSPtr MakeRegularSamplerSPtr(
    const GFA::Size &numSamplesRef)
{
    return std::make_shared<RegularSampler>(numSamplesRef);
}


