#include "RenderThread.hpp"
#include <QTime>

#include <iostream>

RenderThread::RenderThread(RenderJob * const renderJobPtr)
    :   renderJobPtr_(renderJobPtr)
{
}

RenderThread::~RenderThread()
{
}

void RenderThread::run()
{
    QTime timer(0,0);
    
    renderJobPtr_->render();
    std::cout << "Render SEC: " << timer.msecsSinceStartOfDay()/1000.0 << std::endl;
    
    emit renderDone();
}


