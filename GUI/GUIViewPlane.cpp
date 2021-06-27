#include "GUIViewPlane.hpp"
#include <algorithm>

GUIViewPlane::GUIViewPlane(std::shared_ptr<RenderWidget> renderWidgetSPtr)
    : ViewPlane(renderWidgetSPtr->bufferWidth(), renderWidgetSPtr->bufferHeight()),
      renderWidgetSPtr_(renderWidgetSPtr)
{
    constructDebug("GUIViewPlane");
}

GUIViewPlane::~GUIViewPlane()
{
    #ifdef SHARED_POINTER_DEBUG
        std::cout << "\n---- GUIViewPlane:renderWidgetSPtr_ use count = " << renderWidgetSPtr_.use_count() << "\n";
    #endif
    deconstructDebug("GUIViewPlane");
}

void GUIViewPlane::setGUIPixel_(const GFA::Index &x, const GFA::Index &y,
        const GFA::RGBColor &c) const
{
    //NOTE: add warning
    std::min(1,2);
    renderWidgetSPtr_->setPixel(x, y,
        (unsigned char) (std::max(std::min(c.r, 1.0), 0.0) * 255.0),
        (unsigned char) (std::max(std::min(c.g, 1.0), 0.0) * 255.0),
        (unsigned char) (std::max(std::min(c.b, 1.0), 0.0) * 255.0),
        (unsigned char) (std::max(std::min(c.a, 1.0), 0.0) * 255.0));
}



