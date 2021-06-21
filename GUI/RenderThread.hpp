#ifndef __RENDERTHREAD__
#define __RENDERTHREAD__

#include <QtCore/QThread>
#include "Bose.hpp"
#include "FaaRay.hpp"

class RenderThread : public QThread, public Bose
{
    Q_OBJECT

public:
    RenderThread(std::shared_ptr<RenderJob> renderJobSPtr);
    ~RenderThread(void);

    std::shared_ptr<RenderJob> getRenderJobSPtr() { return renderJobSPtr_; }

protected:
    void run();

signals:
    void renderDone();

private:
    std::shared_ptr<RenderJob>   renderJobSPtr_;
};

#endif
