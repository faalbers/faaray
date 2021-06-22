#ifndef __FAARAY_PINHOLECAMERA_H__
#define __FAARAY_PINHOLECAMERA_H__

#include "Shared/Shared.hpp"
#include <memory>
#include "Camera.hpp"

class PinholeCamera : public Camera
{
public:
    PinholeCamera();
    virtual ~PinholeCamera();

    void setViewPlaneDistance(const Scalar &viewPlaneDistance);
    void setZoom(const Scalar &zoom);
    
    void setRayDirection(TraceThread &ttRef) const;

    virtual void render(TraceThread &ttRef) const;
 
private:
    Scalar viewPlaneDistance_;
    Scalar zoom_;
};

typedef std::shared_ptr<PinholeCamera> PinholeCameraSPtr;
PinholeCameraSPtr MakePinholeCameraSPtr();

#endif

