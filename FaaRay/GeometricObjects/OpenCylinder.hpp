#ifndef __FAARAY_OPENCYLINDER_H__
#define __FAARAY_OPENCYLINDER_H__

#include "GeometricObject.hpp"
#include "GFA.hpp"
#include <memory>

namespace FaaRay {

class TraceThread;

class OpenCylinder : public FaaRay::GeometricObject
{
public:
    OpenCylinder();
    ~OpenCylinder(void);     // destructor

    void setRadius(const GFA::Scalar &radius);
    void setBottom(const GFA::Scalar &bottom);
    void setTop(const GFA::Scalar &top);

    virtual bool hit(FaaRay::TraceThread &ttRef, GFA::Scalar &tmin, GFA::Normal &srNormal) const;
    virtual bool shadowHit(FaaRay::TraceThread &ttRef, GFA::Scalar &tmin) const;

private:
    GFA::Scalar     radius_;     // OpenCylinder radius
    GFA::Scalar     bottom_;
    GFA::Scalar     top_;
    GFA::Scalar     invRadius_;
    GFA::Scalar     radiusQuad_; // quadratic OpenCylinder radius
};

typedef std::shared_ptr<OpenCylinder> OpenCylinderSPtr;
OpenCylinderSPtr MakeOpenCylinderSPtr();

}

#endif


