#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QTimer>
#include "Bose.hpp"
#include "RenderThread.hpp"
#include "RenderWidget.hpp"

#ifdef FAARAY_CLASS_DEBUG
    test();
#endif


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Bose
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = NULL);
    ~MainWindow();

public slots:
    void updateOGL() const;
    
protected slots:
    void render();
    void renderDone();

private:
    Ui::MainWindow                  *ui_;
    std::shared_ptr<RenderThread>   renderThreadSPtr_;
    std::shared_ptr<RenderWidget>   renderWidgetSPtr_;


    QTimer              *timer_;

    void viewPlaneSetup_() const;
    void sceneBuild_() const;
};

#endif
