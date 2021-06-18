#include "GeometricObjects/GeometricObject.hpp"
#include "Render/TraceThread.hpp"
#include "Materials/Material.hpp"

GeometricObject::GeometricObject(void)
{
}

GeometricObject::~GeometricObject(void)
{
}

void GeometricObject::setMaterialSPtr(ConstMaterialSPtr materialSPtr)
{
    materialSPtr_ = materialSPtr;
}

ConstMaterialSPtr GeometricObject::getMaterialSPtr() const
{
    return materialSPtr_;
}

