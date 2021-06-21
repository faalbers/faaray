#include "RenderThread.hpp"
#include <QTime>

#include <iostream>

RenderThread::RenderThread(std::shared_ptr<RenderJob> renderJobSPtr)
    :   renderJobSPtr_(renderJobSPtr)
{
    constructDebug("RenderThread");
}

RenderThread::~RenderThread()
{
    sPtrDebug("RenderThread:renderJobSPtr_", renderJobSPtr_);
    deconstructDebug("RenderThread");
}

void RenderThread::run()
{
    QTime timer(0,0);
    
    renderJobSPtr_->render();
    std::cout << "\nRender SEC: " << timer.msecsSinceStartOfDay()/1000.0 << std::endl;
    
    emit renderDone();
}


