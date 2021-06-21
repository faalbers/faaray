#include "Sphere.hpp"
#include "Render/TraceThread.hpp"

Sphere::Sphere()
    : radius_(1.0)
    , radiusQuad_(1.0)
{
    constructDebug("Sphere");
}

Sphere::~Sphere(void)
{
    deconstructDebug("Sphere");
}

bool Sphere::hit(TraceThread &ttRef, Scalar& tmin) const
{
    // page 57
    Vector3D temp = ttRef.rayOrigin - center_;
    Scalar b = 2.0 * (temp * ttRef.rayDirection);
    Scalar c = (temp * temp) - radiusQuad_;
    Scalar disc = (b * b) - (4 * c);

    if (disc < 0.0)
        return false;
    else {
        Scalar t;
        Scalar e = sqrt(disc);
        t = (-b - e) / 2.0; // smaller root
        if (t <= EPSILON)
            t = (-b + e) / 2.0; // larger root
            if (t <= EPSILON)
                return false;

        tmin = t;
        ttRef.srNormal = (temp + ttRef.rayDirection * t) / radius_;
    }
    
    return true;
}

bool Sphere::shadowHit(TraceThread &ttRef, Scalar& tmin) const
{
    // page 57
    Scalar t;
    Vector3D temp = ttRef.sRayOrigin - center_;
    Scalar a = ttRef.sRayDirection * ttRef.sRayDirection;
    Scalar b = 2.0 * (temp * ttRef.sRayDirection);
    Scalar c = (temp * temp) - radiusQuad_;
    Scalar disc = (b * b) - (4 * c);

    if (disc < 0.0)
        return false;
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom; // smaller root

        if (t > EPSILON) {
            tmin = t;
            return true;
        }

        t = (-b + e) / denom; // larger root

        if (t > EPSILON) {
            tmin = t;
            return true;
        }
    }
    
    return false;
}

void Sphere::setCenter(
    const Scalar &x,
    const Scalar &y,
    const Scalar &z)
{
    center_.x = x;
    center_.y = y;
    center_.z = z;
}

void Sphere::setRadius(const Scalar &radius)
{
    radius_ = radius;
    radiusQuad_ = radius_*radius_;
}

SphereSPtr MakeSphereSPtr()
{
    return std::make_shared<Sphere>();
}

/*
void Sphere::setCenter(const Point3D& p)
{
    center.x = p.x;
    center.y = p.y;
    center.z = p.z;
}

bool Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
    // page 57
    double t;
    Vector3D temp = ray.origin - center;
    double a = ray.direction * ray.direction;
    double b = 2.0 * (temp * ray.direction);
    double c = (temp * temp) - (radius * radius);
    double disc = (b * b) - (4 * a * c);
    
    if (disc < 0.0)
        return (false);
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom; // smaller root

        if (t > kEpsilon) {
            tmin = t;
            sr.normal       = (temp + ray.direction * t) / radius;
            sr.localHitPoint = ray.origin + ray.direction * t;
            sr.color = color;
            return (true);
        }

        t = (-b + e) / denom; // larger root

        if (t > kEpsilon) {
            tmin = t;
            sr.normal       = (temp + ray.direction * t) / radius;
            sr.localHitPoint = ray.origin + ray.direction * t;
            sr.color = color;
            return (true);
        }
    }
    
    return (false);
}

bool Sphere::shadowHit(const Ray& ray, double& tmin) const
{
    double t;
    Vector3D temp = ray.origin - center;
    double a = ray.direction * ray.direction;
    double b = 2.0 * (temp * ray.direction);
    double c = (temp * temp) - (radius * radius);
    double disc = (b * b) - (4 * a * c);
    
    if (disc < 0.0)
        return (false);
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom; // smaller root

        if (t > kEpsilon) {
            tmin = t;
            return (true);
        }

        t = (-b + e) / denom; // larger root

        if (t > kEpsilon) {
            tmin = t;
            return (true);
        }
    }
    
    return (false);
}
*/
