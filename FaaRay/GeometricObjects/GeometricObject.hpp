#ifndef __FAARAY_GEOMETRICOBJECT_H__
#define __FAARAY_GEOMETRICOBJECT_H__

#include "Shared/Shared.hpp"

#include <memory>

class TraceThread;
class Material;

class GeometricObject : public Base
{
public:
    GeometricObject();      // default constructor
    ~GeometricObject();     // destructor
    
    virtual bool hit(TraceThread &ttRef, GFA::Scalar &tmin, GFA::Normal &srNormal) const = 0;
    virtual bool shadowHit(TraceThread &ttRef, GFA::Scalar &tmin) const = 0;

    void setMaterialSPtr(std::shared_ptr<const Material> materialSPtr);
    std::shared_ptr<const Material> getMaterialSPtr() const;
    
protected:
    std::shared_ptr<const Material>  materialSPtr_;
};

typedef std::shared_ptr<GeometricObject> GeometricObjectSPtr;

#endif


