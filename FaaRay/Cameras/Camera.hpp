#ifndef __FAARAY_CAMERA_H__
#define __FAARAY_CAMERA_H__

#include "Base/Base.hpp"
#include "GFA.hpp"
#include <memory>

namespace FaaRay {

class TraceThread;

class Camera : public FaaRay::Base
{
public:
    Camera();
    virtual ~Camera();                           

    void setEye(const GFA::Point3D &eye);
    const GFA::Point3D & getEye() const;
    void setLookAt(const GFA::Point3D &lookAt);
   
    void            computeUVW();

    virtual void    render(FaaRay::TraceThread &rp) const = 0;

protected:
    GFA::Point3D  eye_;
    GFA::Point3D  lookAt_;
    GFA::Vector3D up_;
    GFA::Vector3D u_, v_, w_;
};

typedef std::shared_ptr<Camera> CameraSPtr;
typedef std::shared_ptr<const Camera> ConstCameraSPtr;

}

#endif

