#ifndef __FAARAY_REGULARSAMPLER_H__
#define __FAARAY_REGULARSAMPLER_H__

#include <memory>
#include "Samplers/Sampler.hpp"
#include "GFA.hpp"

class RegularSampler : public Sampler
{
    public:
        RegularSampler();
        RegularSampler(const Size &numSamplesRef);
        virtual ~RegularSampler();

        virtual void generateSamples();

};

typedef std::shared_ptr<RegularSampler>  RegularSamplerSPtr;
RegularSamplerSPtr MakeRegularSamplerSPtr();
RegularSamplerSPtr MakeRegularSamplerSPtr(const Size &numSamplesRef);

#endif

