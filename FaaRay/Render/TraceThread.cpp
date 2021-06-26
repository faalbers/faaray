#include "TraceThread.hpp"
//#include "Cameras/Camera.hpp"

#include <algorithm>

FaaRay::TraceThread::TraceThread()
    : srHitAnObject(false)
    , sRayInShadow(false)
{
    constructDebug("TraceThread");
}

FaaRay::TraceThread::~TraceThread()
{
    deconstructDebug("TraceThread");
}

void FaaRay::TraceThread::render()
{
    sceneSPtr->getCameraSPtr()->render(*this);
    viewPlaneSPtr->setPixel(x, y, color);
}

void FaaRay::TraceThread::initRandom(const uint32_t &s)
{
    seedValue_ = s;
    rng_.seed(seedValue_);
}

GFA::Scalar FaaRay::TraceThread::rand()
{
    return distribution(rng_);
}


