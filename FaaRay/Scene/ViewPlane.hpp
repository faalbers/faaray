
#ifndef __FAARAY_VIEWPLANE_H__
#define __FAARAY_VIEWPLANE_H__

#include <memory>
#include "Utils/FaaRay.hpp"
#include "GFA.hpp"
#include "RGBColor.hpp"
#include "RGBColorBuffer.hpp"


class Sampler;

class ViewPlane
{
    public:
        ViewPlane();
        ViewPlane(const Size width, const Size height);
        virtual ~ViewPlane(void);
    
        const Size   & width() const;
        const Size   & height() const;
        const Scalar & pixelSize() const;
        const Size   & numSamples() const;
        
        void setPixel(const Index &x, const Index &y,
            const RGBColor &col) const; 
    
        void setNumSamples(const Size &numSamples);
        const Sampler * getSamplerPtr() const;
        std::shared_ptr<Sampler> getSamplerSPtr() const;
        std::shared_ptr<const Sampler> getConstSamplerSPtr() const;
       
    protected:
        RGBColorBuffer         *frameBufferPtr_;
        Scalar                 pixelSize_;
        std::shared_ptr<Sampler>    samplerSPtr_;
    
        virtual void setGUIPixel_(const Index &x, const Index &y,
            const RGBColor &col) const; 
};

typedef std::shared_ptr<ViewPlane> ViewPlaneSPtr;
typedef std::shared_ptr<const ViewPlane> ConstViewPlaneSPtr;

#endif


