#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>
#include <QPainter>
#include "gfa.hpp"

class RenderWidget : public QWidget
{
    Q_OBJECT

public:
    RenderWidget(QWidget *parent = nullptr);
    RenderWidget(const Size &widthB, const Size &heightB, QWidget *parent = nullptr);

    ~RenderWidget();

    Size bufferWidth();
    Size bufferHeight();

    void resizeBuffer(const Size &width, const Size &height);
    void fillBuffer(char r, char g, char b, char a = 255);

    void setPixel(const Index &kiX, const Index &kiY,
        const unsigned char &r, const unsigned char &g, const unsigned char &b, const unsigned char &a);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    Size            width_, height_;
    unsigned char   *pucBufferPtr_;
};

#endif // RENDERWIDGET_H
