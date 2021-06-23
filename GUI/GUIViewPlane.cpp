#include "GUIViewPlane.hpp"

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
    renderWidgetSPtr_->setPixel(x, y,
        (unsigned char) (c.r * 255.0),
        (unsigned char) (c.g * 255.0),
        (unsigned char) (c.b * 255.0),
        (unsigned char) (c.a * 255.0));
}



