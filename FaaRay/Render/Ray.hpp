#ifndef __FAARAY_RAY_H__
#define __FAARAY_RAY_H__

#include "Point3D.hpp"
#include "Vector3D.hpp"


class Ray
{
    public:
        Ray();
        Ray(const Ray &rayRef);
        Ray(const Point3D &originRef, const Vector3D &directionRef);
        
        void setOrigin(const Point3D &originRef);
    
    private:
        Point3D     origin_;
        Vector3D    direction_;
};

#endif

