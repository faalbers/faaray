#ifndef __FAARAY_BASE_H__
#define __FAARAY_BASE_H__

#include "Shared/Shared.hpp"
#include <memory>

class Base
{
public:
    void constructDebug(const char* name);
    void deconstructDebug(const char* name);
    void sPtrDebug(const char* varName, std::shared_ptr<Base> sPtr, int index = -1);
};

#endif

