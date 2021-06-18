
#ifndef __FAARAY_SCENE_H__
#define __FAARAY_SCENE_H__

#include <vector>
#include <memory>
#include "Utils/FaaRay.hpp"
#include "GFA.hpp"
#include "Point3D.hpp"
#include "RGBColor.hpp"


class Camera;
class Tracer;
class Light;
class TraceThread;
class GeometricObject;

class Scene
{
    public:
        Scene();
        ~Scene(void);

        // Setup methods
        void setCamera(std::shared_ptr<Camera> cameraSPtr);
        void setTracer(std::shared_ptr<Tracer> tracerSPtr);
        void setAmbientLight(std::shared_ptr<Light> ambientLightSPtr);
        
        // add methods
        void addObject(std::shared_ptr<GeometricObject> objectSPtr);
        void addLight(std::shared_ptr<Light> lightSPtr);

        // Retrieving methods
        std::shared_ptr<Camera> getCameraSPtr() const;
        const Tracer * getTracerPtr() const;
        std::shared_ptr<Tracer> getTracerSPtr() const;
        std::shared_ptr<const Tracer> getConstTracerSPtr() const;
        std::shared_ptr<const Light> getConstAmbientLightSPtr() const;
        
        // ray trace methods
        void hitObjects(TraceThread &ttRef) const;
        void shadowHitObjects(TraceThread &ttRef) const;
        void applyLights(TraceThread &ttRef) const;
    
    private:
        std::shared_ptr<Camera>                         cameraSPtr_;
        std::shared_ptr<Tracer>                         tracerSPtr_;
        std::shared_ptr<Light>                          ambientLightSPtr_;
        std::vector<std::shared_ptr<GeometricObject>>   objectSPtrs_;
        std::vector<std::shared_ptr<Light>>             lightSPtrs_;

};

typedef std::shared_ptr<Scene> SceneSPtr;
typedef std::shared_ptr<const Scene> ConstSceneSPtr;

#endif


