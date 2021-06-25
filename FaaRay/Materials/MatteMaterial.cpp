#include "MatteMaterial.hpp"
#include "GFA.hpp"
#include "BRDFs/LambertianBRDF.hpp"
#include "Render/TraceThread.hpp"
#include "Lights/Light.hpp"

FaaRay::MatteMaterial::MatteMaterial()
    :   ambientBrdfPtr_(new FaaRay::LambertianBRDF),
        diffuseBrdfPtr_(new FaaRay::LambertianBRDF)
{
    constructDebug("FaaRay::MatteMaterial");
}

FaaRay::MatteMaterial::~MatteMaterial()
{
    deconstructDebug("FaaRay::MatteMaterial");
    delete ambientBrdfPtr_;
    delete diffuseBrdfPtr_;
}

void FaaRay::MatteMaterial::setCd(
            const GFA::Scalar &r,
            const GFA::Scalar &g,
            const GFA::Scalar &b) const
{
    ambientBrdfPtr_->setCd(r, g, b);
    diffuseBrdfPtr_->setCd(r, g, b);
}

const GFA::RGBColor & FaaRay::MatteMaterial::getDiffuseCd() const
{
    return diffuseBrdfPtr_->getCd();
}

void FaaRay::MatteMaterial::shade(FaaRay::TraceThread &ttRef) const
{
    // Ambient BRDF reflectance mult Ambient Light 
    ambientBrdfPtr_->rho(ttRef);
    diffuseBrdfPtr_->f(ttRef);
    ttRef.ambientLightSPtr->L(ttRef);
    ttRef.srColor = ttRef.srRhoColor * ttRef.srAmbientL;
    
    //ttRef.srColor *= GFA::Normal(0.0,0.0,1.0) * ttRef.srNormal;
    
    // Add receiving lights.
    //ttRef.sceneSPtr->applyLights(ttRef);
    GFA::Scalar ndotwi;
    std::vector<FaaRay::LightSPtr> lightSPtrs(ttRef.sceneSPtr->getLightSPtrs());
    for (GFA::Index j = 0; j < lightSPtrs.size(); j++) {
        // get light direction vector from light to hit point
        lightSPtrs[j]->getDirection(ttRef);
        // get multiplier between light and surface vectors
        ndotwi = ttRef.lDirection * ttRef.srNormal;
        if (ndotwi > 0.0) {
            if (lightSPtrs[j]->castsShadows()) {
                ttRef.sRayOrigin = ttRef.srHitPoint;
                ttRef.sRayDirection = ttRef.lDirection;
                // check if surface point is obscured from the light by any other object
                ttRef.sceneSPtr->shadowHitObjects(ttRef);
            }

            if ( !ttRef.sRayInShadow ) {
                lightSPtrs[j]->L(ttRef);
                ttRef.srColor += ttRef.srFColor * ttRef.srLightL * ndotwi;
            }
        }
    }
}

void FaaRay::MatteMaterial::diffuse(FaaRay::TraceThread &ttRef) const
{
}


