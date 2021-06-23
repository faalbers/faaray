#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>
#include <QPainter>
#include "Bose.hpp"

class RenderWidget : public QWidget, public Bose
{
    Q_OBJECT

public:
    RenderWidget(QWidget *parent = nullptr);
    RenderWidget(const GFA::Size &widthB, const GFA::Size &heightB, QWidget *parent = nullptr);

    ~RenderWidget();

    GFA::Size bufferWidth();
    GFA::Size bufferHeight();

    void resizeBuffer(const GFA::Size &width, const GFA::Size &height);
    void resizeSBuffer(const GFA::Size &width, const GFA::Size &height);
    void fillBuffer(char r, char g, char b, char a = 255);
    void fillSBuffer(char r, char g, char b, char a = 255);

    void setPixel(const GFA::Index &kiX, const GFA::Index &kiY,
        const unsigned char &r, const unsigned char &g, const unsigned char &b, const unsigned char &a);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    GFA::Size            width_, height_;
    std::shared_ptr<unsigned char>  pucBufferSPtr_;
};

#endif // RENDERWIDGET_H
