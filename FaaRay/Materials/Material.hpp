#ifndef __FAARAY_MATERIAL_H__
#define __FAARAY_MATERIAL_H__

#include "Shared.hpp"

#include "GFA.hpp"
#include <memory>
    
class TraceThread;

class Material : public Base
{
    public:
        Material();
        virtual ~Material();

        virtual const RGBColor & getDiffuseCd() const { return color_; }
        virtual void shade(TraceThread &ttRef) const = 0;
        virtual void diffuse(TraceThread &ttRef) const = 0;

        void setColor() { color_.r = 0.0;}
    
    protected:
        RGBColor color_;
};

typedef std::shared_ptr<Material>  MaterialSPtr;
typedef std::shared_ptr<const Material>  ConstMaterialSPtr;

#endif

