#ifndef __FAARAY_RENDERJOB_H__
#define __FAARAY_RENDERJOB_H__

#include "Shared.hpp"

#include <memory>

class Scene;
class ViewPlane;
class TraceThread;

class RenderJob : public Base
{
public:
    RenderJob();
    ~RenderJob();

    std::shared_ptr<Scene>      getSceneSPtr() const;
    std::shared_ptr<ViewPlane>  getViewPlaneSPtr() const;

    void setViewPlaneSPtr(std::shared_ptr<ViewPlane> viewPlaneSPtr);

    void setMultiThread();
    
    void render() const;

private:
    // NeedFix: create typedefs for these
    std::shared_ptr<ViewPlane>  viewPlaneSPtr_;
    std::shared_ptr<Scene>      sceneSPtr_;
    bool                        multiThread_;
    

    
    void renderOneThread_() const;
    void renderMultiThread_() const;
    void setupTraceThread_(TraceThread &rt) const;
};

#endif

