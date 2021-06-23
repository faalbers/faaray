#ifndef __FAARAY_SPHERE_H__
#define __FAARAY_SPHERE_H__

#include "Shared/Shared.hpp"
#include <memory>
#include "GeometricObject.hpp"

class Sphere : public GeometricObject
{
public:
    Sphere();
    ~Sphere(void);     // destructor

    void setCenter(
        const GFA::Scalar &x,
        const GFA::Scalar &y,
        const GFA::Scalar &z);
    void setRadius(const GFA::Scalar &radius);

    virtual bool hit(TraceThread &ttRef, GFA::Scalar &tmin, GFA::Normal &srNormal) const;
    virtual bool shadowHit(TraceThread &ttRef, GFA::Scalar &tmin) const;

private:
    GFA::Point3D    center_;    // center point of the sphere
    GFA::Scalar     radius_;     // sphere radius
    GFA::Scalar     radiusQuad_; // quadratic sphere radius
};

typedef std::shared_ptr<Sphere> SphereSPtr;
SphereSPtr MakeSphereSPtr();

#endif


