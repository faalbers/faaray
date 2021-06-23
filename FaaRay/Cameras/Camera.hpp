#ifndef __FAARAY_CAMERA_H__
#define __FAARAY_CAMERA_H__

#include "Shared/Shared.hpp"
#include <memory>

class TraceThread;

class Camera : public Base
{
public:
    Camera();
    virtual ~Camera();                           

    void setEye(const GFA::Point3D &eye);
    const GFA::Point3D & getEye() const;
    void setLookAt(const GFA::Point3D &lookAt);
   
    void            computeUVW();

    virtual void    render(TraceThread &rp) const = 0;

protected:
    GFA::Point3D  eye_;
    GFA::Point3D  lookAt_;
    GFA::Vector3D up_;
    GFA::Vector3D u_, v_, w_;
};

typedef std::shared_ptr<Camera> CameraSPtr;

#endif

