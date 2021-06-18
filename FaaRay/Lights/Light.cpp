#include "Lights/Light.hpp"
#include "Render/TraceThread.hpp"

Light::Light()
    :   shadows_(false)
{
}

Light::~Light()
{
}

const bool & Light::castsShadows() const
{
    return shadows_;
}

void Light::castShadows(const bool &shadows)
{
    shadows_ = shadows;
}


