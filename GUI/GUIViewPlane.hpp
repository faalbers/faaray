#ifndef __GUIVIEWPLANE_H__
#define __GUIVIEWPLANE_H__

#include <memory>
#include "Render/RenderJob.hpp"
#include "RGBColor.hpp"
#include "RenderWidget.hpp"
#include "Scene/ViewPlane.hpp"

class GUIViewPlane : public ViewPlane
{
public:
    GUIViewPlane(RenderWidget *renderWidgetPtr_);

private:
    RenderWidget  *renderWidgetPtr_;

    virtual void setGUIPixel_(const Index &x, const Index &y,
        const RGBColor &c) const; 
};

typedef std::shared_ptr<GUIViewPlane> GUIViewPlaneSPtr;

#endif

