#include "Render/TraceThread.hpp"
#include "Scene/ViewPlane.hpp"
#include "Scene/Scene.hpp"
#include "Samplers/Sampler.hpp"
#include "Cameras/Camera.hpp"
#include "Tracers/Tracer.hpp"
#include "Lights/Light.hpp"
#include "Materials/Material.hpp"
#include "RGBcolor.hpp"

TraceThread::TraceThread()
{
}

void TraceThread::render()
{
    sceneSPtr->getCameraSPtr()->render(*this);
    viewPlaneSPtr->setPixel(x, y, color);
}

void TraceThread::initRandom(const uint32_t &s)
{
    seedValue_ = s;
    rng_.seed(seedValue_);
}

Scalar TraceThread::rand()
{
    return distribution(rng_);
}


