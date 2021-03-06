
#ifndef __GFA_RGBCOLORBUFFER_H__
#define __GFA_RGBCOLORBUFFER_H__

#include "Shared/Shared.hpp"

namespace GFA {
class RGBColor;

// NeedFix: change this to a RGBA8888 buffer
class RGBColorBuffer
{
    public:
        RGBColorBuffer();
        RGBColorBuffer(const Size &width, const Size &height);
        ~RGBColorBuffer();
    
        const Size & width() const;
        const Size & height() const;

        void setPixel(const Index &x, const Index &y, const RGBColor &col);

    private:
        Size    width_;
        Size    height_;
        Size    size_;
        Scalar  *dataPtr_;
};

}

#endif


