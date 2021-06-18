#include "GUIViewPlane.hpp"

GUIViewPlane::GUIViewPlane(RenderWidget *renderWidgetPtr)
    : ViewPlane(renderWidgetPtr->bufferWidth(), renderWidgetPtr->bufferHeight()),
      renderWidgetPtr_(renderWidgetPtr)
{
}

void GUIViewPlane::setGUIPixel_(const Index &x, const Index &y,
        const RGBColor &c) const
{
    //NOTE: add warning
    if (renderWidgetPtr_ == 0 ) return;
    renderWidgetPtr_->setPixel(x, y,
        (unsigned char) (c.r * 255.0),
        (unsigned char) (c.g * 255.0),
        (unsigned char) (c.b * 255.0),
        (unsigned char) (c.a * 255.0));
}



