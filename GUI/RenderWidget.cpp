#include "RenderWidget.hpp"
#include <iostream>

RenderWidget::RenderWidget(QWidget *parent)
    : QWidget(parent)
    , width_(0)
    , height_(0)
{
    constructDebug("RenderWidget");
}

RenderWidget::RenderWidget(const GFA::Size &widthB, const GFA::Size &heightB, QWidget *parent)
    : QWidget(parent)
    , width_(widthB)
    , height_(heightB)
{
    resizeBuffer(widthB, heightB);

    constructDebug("RenderWidget");
}

RenderWidget::~RenderWidget()
{
    sPtrDebug("RenderWidget:pucBufferSPtr_", pucBufferSPtr_);
    deconstructDebug("RenderWidget");
}

GFA::Size RenderWidget::bufferWidth() { return width_; }

GFA::Size RenderWidget::bufferHeight() { return height_; }

void RenderWidget::resizeBuffer(const GFA::Size &widthB, const GFA::Size &heightB)
{
    const int frameBufferSize = widthB * heightB;
    const int frameBufferSizeBytes = frameBufferSize * sizeof(uint32_t);
    pucBufferSPtr_.reset(new unsigned char[frameBufferSizeBytes]);
    width_ = widthB;
    height_ = heightB;
    fillBuffer(0, 0, 0, 50);
    update();
}

void RenderWidget::fillBuffer(char r, char g, char b, char a)
{
    uint32_t color = 0;
    uint32_t *fb32 = (uint32_t *) pucBufferSPtr_.get();
    const size_t size = width_ * height_;
    color <<= 8; color |= a;
    color <<= 8; color |= b;
    color <<= 8; color |= g;
    color <<= 8; color |= r;
    for (size_t i=0; i<size; i++) fb32[i] = color;
}

void RenderWidget::paintEvent(QPaintEvent *event)
{
    QImage image(pucBufferSPtr_.get(), width_, height_, QImage::Format_RGBA8888);
    image.mirror(false, true);
    QPainter p(this);
    QRect area(0, 0, width_, height_);
    p.drawImage(area, image, area);
}

void RenderWidget::mousePressEvent(QMouseEvent *event)
{
    //fillBuffer(0, 0, 255);
    update();
}

void RenderWidget::setPixel(const GFA::Index &kiX, const GFA::Index &kiY,
    const unsigned char &r, const unsigned char &g, const unsigned char &b, const unsigned char &a)
{
   if (kiX >= width_ || kiY >= height_) return;

   pucBufferSPtr_.get()[kiX*4 + kiY*width_*4]      = r;
   pucBufferSPtr_.get()[kiX*4 + 1   +kiY*width_*4] = g;
   pucBufferSPtr_.get()[kiX*4 + 2   +kiY*width_*4] = b;
   // NeedFix: Alpha also needs to be handled
   //pucBufferPtr_[kiX*4 + 3   +kiY*width_*4] = a;
   pucBufferSPtr_.get()[kiX*4 + 3   +kiY*width_*4] = 0xFF;
}



