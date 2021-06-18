#ifndef __RENDERTHREAD__
#define __RENDERTHREAD__

#include <QtCore/QThread>
#include "Render/RenderJob.hpp"

class RenderThread : public QThread
{
    Q_OBJECT

public:
    RenderThread(RenderJob * const renderJobPtr);
    ~RenderThread(void);

protected:
    void run();

signals:
    void renderDone();

private:
    RenderJob   *renderJobPtr_;
    
};

#endif
