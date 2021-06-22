#ifndef __FAARAY_POINTLIGHT_H__
#define __FAARAY_POINTLIGHT_H__

#include "Shared/Shared.hpp"

#include "Lights/Light.hpp"
#include <memory>

class PointLight : public Light
{
public:
    PointLight();
    virtual ~PointLight();

    void setCenter(
        const Scalar &x,
        const Scalar &y,
        const Scalar &z);

    virtual void getDirection(TraceThread &ttRef) const;
    virtual void L(TraceThread &ttRef) const;
    virtual void inShadow(TraceThread &ttRef) const;    

    void setRadiance(const Scalar b) { ls_ = b; }
    void setColor(const RGBColor color) { color_ = color; }

private:
    Point3D    center_; // center point of the point light
    Scalar     ls_;     // light strength
    RGBColor   color_;  // light color
};

typedef std::shared_ptr<PointLight>  PointLightSPtr;
PointLightSPtr MakePointLightSPtr();

#endif

