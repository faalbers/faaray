#ifndef __FAARAY_CAMERA_H__
#define __FAARAY_CAMERA_H__

#include <memory>
#include "Utils/FaaRay.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

class TraceThread;

class Camera
{
public:
    Camera();
    virtual ~Camera();                           

    void setEye(const Point3D &eye);
    const Point3D & getEye() const;
    void setLookAt(const Point3D &lookAt);
   
    void            computeUVW();

    virtual void    render(TraceThread &rp) const = 0;

protected:
    Point3D  eye_;
    Point3D  lookAt_;
    Vector3D up_;
    Vector3D u_, v_, w_;
};

typedef std::shared_ptr<Camera> CameraSPtr;

#endif

