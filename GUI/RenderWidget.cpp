#include "renderwidget.hpp"
#include <iostream>

RenderWidget::RenderWidget(QWidget *parent)
    : QWidget(parent)
    , width_(0)
    , height_(0)
    , pucBufferPtr_(nullptr)
{
}

RenderWidget::RenderWidget(const Size &widthB, const Size &heightB, QWidget *parent)
    : QWidget(parent)
    , width_(widthB)
    , height_(heightB)
    , pucBufferPtr_(nullptr)
{
    resizeBuffer(widthB, heightB);
}

Size RenderWidget::bufferWidth() { return width_; }

Size RenderWidget::bufferHeight() { return height_; }

void RenderWidget::resizeBuffer(const Size &widthB, const Size &heightB)
{
    const int frameBufferSize = widthB * heightB;
    const int frameBufferSizeBytes = frameBufferSize * sizeof(uint32_t);
    if ( pucBufferPtr_ == nullptr ) {
        pucBufferPtr_ = new unsigned char[frameBufferSizeBytes];
    } else {
        if ( frameBufferSize != (width_ * height_) ) {
            if (pucBufferPtr_ != nullptr) delete[] pucBufferPtr_;
            pucBufferPtr_ = new unsigned char[frameBufferSizeBytes];
        }
    }
    width_ = widthB;
    height_ = heightB;
    fillBuffer(0, 0, 0, 50);
    update();
}

void RenderWidget::fillBuffer(char r, char g, char b, char a)
{
    uint32_t color = 0;
    uint32_t *fb32 = (uint32_t *) pucBufferPtr_;
    const size_t size = width_ * height_;
    color <<= 8; color |= a;
    color <<= 8; color |= b;
    color <<= 8; color |= g;
    color <<= 8; color |= r;
    for (size_t i=0; i<size; i++) fb32[i] = color;
}

void RenderWidget::paintEvent(QPaintEvent *event)
{
    QImage image(pucBufferPtr_, width_, height_, QImage::Format_RGBA8888);
    QPainter p(this);
    QRect area(0, 0, width_, height_);
    p.drawImage(area, image, area);
}

void RenderWidget::mousePressEvent(QMouseEvent *event)
{
    //fillBuffer(0, 0, 255);
    update();
}

void RenderWidget::setPixel(const Index &kiX, const Index &kiY,
    const unsigned char &r, const unsigned char &g, const unsigned char &b, const unsigned char &a)
{
   if (kiX >= width_ || kiY >= height_) return;

   pucBufferPtr_[kiX*4 + kiY*width_*4] = r;
   pucBufferPtr_[kiX*4 + 1   +kiY*width_*4] = g;
   pucBufferPtr_[kiX*4 + 2   +kiY*width_*4] = b;
   pucBufferPtr_[kiX*4 + 3   +kiY*width_*4] = 0xFF;
}

RenderWidget::~RenderWidget()
{
    if (pucBufferPtr_ != nullptr) delete[] pucBufferPtr_;
}


