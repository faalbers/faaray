#include "Camera.hpp"
#include "Render/TraceThread.hpp"

Camera::Camera()
{
    up_.y = 1.0; // set up vector
}

Camera::~Camera()
{
}

void Camera::setEye(const GFA::Point3D &eye)
{
    eye_ = eye;
}

const GFA::Point3D & Camera::getEye() const
{
    return eye_;
}

void Camera::setLookAt(const GFA::Point3D &lookAt)
{
    lookAt_ = lookAt;
}

void Camera::computeUVW()
{
    // take care of up and down singularities
    if ( eye_.x == lookAt_.x && eye_.z == lookAt_.z ) {
        if ( eye_.y > lookAt_.y ) {
            u_.x = 0.0; u_.y = 0.0; u_.z = 1.0; 
            v_.x = 1.0; v_.y = 0.0; v_.z = 0.0; 
            w_.x = 0.0; w_.y = 1.0; w_.z = 0.0; 
            return;
        } else if ( eye_.y < lookAt_.y ) {
            u_.x = 1.0; u_.y = 0.0; u_.z = 0.0; 
            v_.x = 0.0; v_.y = 0.0; v_.z = 1.0; 
            w_.x = 0.0; w_.y = -1.0; w_.z = 0.0; 
            return;
        }
    }

    w_ = eye_ - lookAt_;
    w_.normalize();
    u_ = up_ ^ w_;
    u_.normalize();
    v_ = w_ ^ u_;
}


