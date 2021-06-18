#ifndef __FAARAY_SPHERE_H__
#define __FAARAY_SPHERE_H__

#include <memory>
#include "Utils/FaaRay.hpp"
#include "GeometricObjects/GeometricObject.hpp"
#include "GFA.hpp"
#include "Point3D.hpp"

class Sphere : public GeometricObject
{
public:
    Sphere();
    ~Sphere(void);     // destructor

    void setCenter(
        const Scalar &x,
        const Scalar &y,
        const Scalar &z);
    void setRadius(const Scalar &radius);

    virtual bool hit(TraceThread &ttRef, Scalar &tmin) const;
    virtual bool shadowHit(TraceThread &ttRef, Scalar &tmin) const;

private:
    Point3D    center_;    // center point of the sphere
    Scalar     radius_;     // sphere radius
    Scalar     radiusQuad_; // quadratic sphere radius
};

typedef std::shared_ptr<Sphere> SphereSPtr;
SphereSPtr MakeSphereSPtr();

#endif


