#include "MatteMaterial.hpp"
#include "GFA.hpp"
#include "BRDFs/LambertianBRDF.hpp"
#include "Render/TraceThread.hpp"

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
    ttRef.sceneSPtr->applyLights(ttRef);
    
    /*
    GFA::Vector3D    wo = -sr.ray.direction;
    // Ambient BRDF reflectance mult Ambient Light 
    GFA::RGBColor L = ambientBrdf->rho(sr, wo) * sr.world.ambientPtr->L(sr);

    int numLights = sr.world.lights.size();
    for (int j = 0; j < numLights; j++) {
        GFA::Vector3D wi = sr.world.lights[j]->getDirection(sr);
        double ndotwi = wi * sr.normal;
        
        if (ndotwi > 0.0) {
            bool inShadow = false;
            
            if ( sr.world.lights[j]->castsShadows() ) {
                Ray shadowRay(sr.hitPoint, wi);
                inShadow = sr.world.lights[j]->inShadow(shadowRay, sr);
            }
            if (!inShadow) 
                L += diffuseBrdf->f(sr, wi, wo) * sr.world.lights[j]->L(sr) * ndotwi;
        }
    }
    
    return L;
    */
}

void FaaRay::MatteMaterial::diffuse(FaaRay::TraceThread &ttRef) const
{
}


