#ifndef __FAARAY_LIGHT_H__
#define __FAARAY_LIGHT_H__

#include <memory>


class TraceThread;
    
class Light
{
public:
    Light();
    virtual ~Light();

    virtual void getDirection(TraceThread &ttRef) const = 0;
    virtual void L(TraceThread &ttRef) const = 0;
    virtual void inShadow(TraceThread &ttRef) const = 0;

    const bool & castsShadows() const;
    void castShadows(const bool &shadows);

protected:
    bool    shadows_;
};

typedef std::shared_ptr<Light> LightSPtr;
typedef std::shared_ptr<const Light> ConstLightSPtr;

#endif

