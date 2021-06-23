#ifndef __FAARAY_AMBIENTLIGHT_H__
#define __FAARAY_AMBIENTLIGHT_H__

#include "Shared/Shared.hpp"

#include "Lights/Light.hpp"
#include <memory>

class AmbientLight : public Light
{
public:
    AmbientLight();
    virtual ~AmbientLight();

    virtual void getDirection(TraceThread &ttRef) const;
    virtual void L(TraceThread &ttRef) const;
    virtual void inShadow(TraceThread &ttRef) const;    
    
    void setLs(const GFA::Scalar &ls);

private:
    GFA::Scalar     ls_;     // light strength
    GFA::RGBColor   color_;  // light color
};

typedef std::shared_ptr<AmbientLight>  AmbientLightSPtr;
AmbientLightSPtr MakeAmbientLightSPtr();

#endif

