#ifndef __FAARAY_MULTIJITTEREDSAMPLER_H__
#define __FAARAY_MULTIJITTEREDSAMPLER_H__

#include <memory>
#include "Samplers/Sampler.hpp"
#include "GFA.hpp"

class MultiJitteredSampler : public Sampler
{
    public:
        MultiJitteredSampler();
        MultiJitteredSampler(const Size &numSamplesRef);
        virtual ~MultiJitteredSampler();

        virtual void generateSamples();
};

typedef std::shared_ptr<MultiJitteredSampler>  MultiJitteredSamplerSPtr;
MultiJitteredSamplerSPtr MakeMultiJitteredSamplerSPtr();
MultiJitteredSamplerSPtr MakeMultiJitteredSamplerSPtr(const Size &numSamplesRef);

#endif

