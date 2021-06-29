#include "RenderThread.hpp"
#include "FaaRay.hpp"
#include <iostream>
#include <chrono>

RenderThread::RenderThread(std::shared_ptr<FaaRay::RenderJob> renderJobSPtr)
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
    auto t1 = std::chrono::high_resolution_clock::now();
    renderJobSPtr_->render();
    auto t2 = std::chrono::high_resolution_clock::now();

    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "Render Time: " << ms_int.count() << "ms\n";

    emit renderDone();
}


