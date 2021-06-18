#include "Samplers/RegularSampler.hpp"

RegularSampler::RegularSampler()
    :   Sampler()
{
    generateSamples();
}

RegularSampler::RegularSampler(const Size &numSamplesRef)
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
    for (Index p = 0; p < numSets_; p++) {
        for (Index j = 0; j < numOneDimSamples_; j++) {
            for (Index k = 0; k < numOneDimSamples_; k++) {
                Point2D sp(
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
    const Size &numSamplesRef)
{
    return std::make_shared<RegularSampler>(numSamplesRef);
}


