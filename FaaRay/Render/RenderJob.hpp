#ifndef __FAARAY_RENDERJOB_H__
#define __FAARAY_RENDERJOB_H__

#include <memory>
#include "Utils/FaaRay.hpp"
//#include "tbb/parallel_for.hpp"
//#include "tbb/blocked_range.hpp"


class Scene;
class ViewPlane;
class TraceThread;

class RenderJob
{
public:
    RenderJob();
    ~RenderJob();

    std::shared_ptr<Scene>      getSceneSPtr() const;
    std::shared_ptr<ViewPlane>  getViewPlaneSPtr() const;

    void setViewPlaneSPtr(std::shared_ptr<ViewPlane> viewPlaneSPtr);

    void setMultiThread();
    
    void render() const;

    //void operator() (const tbb::blocked_range<std::size_t> &r) const;

private:
    std::shared_ptr<ViewPlane>  viewPlaneSPtr_;
    std::shared_ptr<Scene>      sceneSPtr_;
    bool                        multiThread_;
    

    
    void renderOneThread_() const;
    void renderMultiThread_() const;
    void setupTraceThread_(TraceThread &rt) const;
};

#endif

