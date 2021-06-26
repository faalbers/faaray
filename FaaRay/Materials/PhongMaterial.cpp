#include "PhongMaterial.hpp"
#include "GFA.hpp"
#include "BRDFs/LambertianBRDF.hpp"
#include "BRDFs/GlossySpecularBRDF.hpp"
#include "Render/TraceThread.hpp"
#include "Lights/Light.hpp"

FaaRay::PhongMaterial::PhongMaterial()
    : ambientBrdfPtr_(new FaaRay::LambertianBRDF)
    , diffuseBrdfPtr_(new FaaRay::LambertianBRDF)
    , specularBrdfPtr_(new FaaRay::GlossySpecularBRDF)
{
    constructDebug("FaaRay::PhongMaterial");
}

FaaRay::PhongMaterial::~PhongMaterial()
{
    deconstructDebug("FaaRay::PhongMaterial");
    delete ambientBrdfPtr_;
    delete diffuseBrdfPtr_;
}

void FaaRay::PhongMaterial::setCd(
            const GFA::Scalar &r,
            const GFA::Scalar &g,
            const GFA::Scalar &b) const
{
    ambientBrdfPtr_->setCd(r, g, b);
    diffuseBrdfPtr_->setCd(r, g, b);
}

const GFA::RGBColor & FaaRay::PhongMaterial::getDiffuseCd() const
{
    return diffuseBrdfPtr_->getCd();
}

void FaaRay::PhongMaterial::shade(FaaRay::TraceThread &ttRef) const
{
    // Ambient BRDF reflectance mult Ambient Light 
    ambientBrdfPtr_->rho(ttRef);
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
        // now that the direction is set we can run the BRDF f
        diffuseBrdfPtr_->f(ttRef);
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

void FaaRay::PhongMaterial::diffuse(FaaRay::TraceThread &ttRef) const
{
}

