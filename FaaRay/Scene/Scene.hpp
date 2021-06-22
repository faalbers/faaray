
#ifndef __FAARAY_SCENE_H__
#define __FAARAY_SCENE_H__

#include "Shared/Shared.hpp"

#include <vector>
#include <memory>

class Camera;
class Tracer;
class Light;
class TraceThread;
class GeometricObject;

class Scene : public Base
{
    public:
        Scene();
        ~Scene();

        // Setup methods
        // NeedFix: change shared ptr declarators
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

        // SPtr test function
        void printSPtrUseCounts();
        
        // ray trace methods
        void hitObjects(TraceThread &ttRef) const;
        void shadowHitObjects(TraceThread &ttRef) const;
        void applyLights(TraceThread &ttRef) const;
    
    private:
        // NeedFix: change std::shared_ptr<Camera> to CameraSPtr
        std::shared_ptr<Camera>                         cameraSPtr_;
        std::shared_ptr<Tracer>                         tracerSPtr_;
        std::shared_ptr<Light>                          ambientLightSPtr_;
        std::vector<std::shared_ptr<GeometricObject>>   objectSPtrs_;
        std::vector<std::shared_ptr<Light>>             lightSPtrs_;

};

typedef std::shared_ptr<Scene> SceneSPtr;
typedef std::shared_ptr<const Scene> ConstSceneSPtr;

#endif


