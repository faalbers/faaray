#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QTimer>
#include "RenderThread.hpp"
#include "RenderWidget.hpp"
#include "Render/RenderJob.hpp"
//#include "Scene/Scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
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
    Ui::MainWindow      *ui_;
    RenderThread        *renderThreadPtr_;
    RenderWidget        *renderWidgetPtr_;
    RenderJob   *renderJobPtr_;
    //Scene       *scenePtr_;
    //ViewPlane   *viewPlanePtr_;
    QTimer              *timer_;

    void viewPlaneSetup_() const;
    void sceneBuild_() const;
};

#endif
