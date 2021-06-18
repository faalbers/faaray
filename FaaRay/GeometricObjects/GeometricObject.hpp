#ifndef __FAARAY_GEOMETRICOBJECT_H__
#define __FAARAY_GEOMETRICOBJECT_H__

#include <memory>
#include "GFA.hpp"
#include "Utils/FaaRay.hpp"


class TraceThread;
class Material;

class GeometricObject
{
public:
    GeometricObject();      // default constructor
    ~GeometricObject();     // destructor
    
    virtual bool hit(TraceThread &ttRef, Scalar &tmin) const = 0;
    virtual bool shadowHit(TraceThread &ttRef, Scalar &tmin) const = 0;

    void setMaterialSPtr(std::shared_ptr<const Material> materialSPtr);
    std::shared_ptr<const Material> getMaterialSPtr() const;
    
protected:
    std::shared_ptr<const Material>  materialSPtr_;
};

typedef std::shared_ptr<GeometricObject> GeometricObjectSPtr;

#endif


