#ifndef __GUIVIEWPLANE_H__
#define __GUIVIEWPLANE_H__

#include <memory>
#include "FaaRay.hpp"
#include "RenderWidget.hpp"

class GUIViewPlane : public ViewPlane
{
public:
    GUIViewPlane(std::shared_ptr<RenderWidget> renderWidgetSPtr);
    ~GUIViewPlane();

private:
    std::shared_ptr<RenderWidget>  renderWidgetSPtr_;

    virtual void setGUIPixel_(const Index &x, const Index &y,
        const RGBColor &c) const; 
};

typedef std::shared_ptr<GUIViewPlane> GUIViewPlaneSPtr;

#endif

