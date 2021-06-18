#ifndef __FAARAY_SAMPLER_H__
#define __FAARAY_SAMPLER_H__

#include <memory>
#include <vector>
#include "GFA.hpp"
#include "Utils/FaaRay.hpp"
#include "Point2D.hpp"

class TraceThread;

class Sampler
{
    public:
        Sampler();
        Sampler(const Size &numSamplesRef);
        virtual ~Sampler();
        
        const Size & numSamples() const;
        
        virtual void generateSamples() = 0;
        void setupShuffledIndices();
    
        void setSampleUnitSquare(TraceThread &ttRef) const;
        
    protected:
        Size                   numOneDimSamples_;  // one dim of samples
        Size                   numSamples_;        // sample count in set
        Size                   numSets_;           // sample sets count
        std::vector<Point2D>   samples_;
        std::vector<Index>     shuffledIndices_;
        MyRNG       rng_;
        std::uniform_real_distribution<Scalar> distribution;  
        Scalar rand_();
};

typedef std::shared_ptr<Sampler>  SamplerSPtr;
typedef std::shared_ptr<const Sampler>  ConstSamplerSPtr;

#endif


