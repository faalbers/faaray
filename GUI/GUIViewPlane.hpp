#ifndef __GUIVIEWPLANE_H__
#define __GUIVIEWPLANE_H__

#include <memory>
#include "GFA.hpp"
#include "FaaRay.hpp"
#include "RenderWidget.hpp"

class GUIViewPlane : public FaaRay::ViewPlane
{
public:
    GUIViewPlane(std::shared_ptr<RenderWidget> renderWidgetSPtr);
    ~GUIViewPlane();

private:
    std::shared_ptr<RenderWidget>  renderWidgetSPtr_;

    virtual void setGUIPixel_(const GFA::Index &x, const GFA::Index &y,
        const GFA::RGBColor &c) const; 
};

typedef std::shared_ptr<GUIViewPlane> GUIViewPlaneSPtr;

#endif

