#include "MatteMaterial.hpp"
#include "Render/TraceThread.hpp"
#include "BRDFs/LambertianBRDF.hpp"
#include "Lights/Light.hpp"
#include "Scene/Scene.hpp"

MatteMaterial::MatteMaterial()
    :   ambientBrdfPtr_(new LambertianBRDF),
        diffuseBrdfPtr_(new LambertianBRDF)
{
    constructDebug("MatteMaterial");
}

MatteMaterial::~MatteMaterial()
{
    deconstructDebug("MatteMaterial");
    delete ambientBrdfPtr_;
    delete diffuseBrdfPtr_;
}

void MatteMaterial::setCd(
            const Scalar &r,
            const Scalar &g,
            const Scalar &b) const
{
    ambientBrdfPtr_->setCd(r, g, b);
    diffuseBrdfPtr_->setCd(r, g, b);
}

const RGBColor & MatteMaterial::getDiffuseCd() const
{
    return diffuseBrdfPtr_->getCd();
}

void MatteMaterial::shade(TraceThread &ttRef) const
{
    // Ambient BRDF reflectance mult Ambient Light 
    ambientBrdfPtr_->rho(ttRef);
    diffuseBrdfPtr_->f(ttRef);
    ttRef.ambientLightSPtr->L(ttRef);
    ttRef.srColor = ttRef.srRhoColor * ttRef.srAmbientL;
    
    //ttRef.srColor *= Normal(0.0,0.0,1.0) * ttRef.srNormal;
    
    // Add receiving lights.
    ttRef.sceneSPtr->applyLights(ttRef);
    
    /*
    Vector3D    wo = -sr.ray.direction;
    // Ambient BRDF reflectance mult Ambient Light 
    RGBColor L = ambientBrdf->rho(sr, wo) * sr.world.ambientPtr->L(sr);

    int numLights = sr.world.lights.size();
    for (int j = 0; j < numLights; j++) {
        Vector3D wi = sr.world.lights[j]->getDirection(sr);
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

void MatteMaterial::diffuse(TraceThread &ttRef) const
{
}


