#ifndef __GUI_BASE_H__
#define __GUI_BASE_H__

#include <memory>
#include "FaaRay.hpp"
// NeedFix: need too start using namespaces to fix Base and Bose concflict
class Bose
{
public:
    void constructDebug(const char* name);
    void deconstructDebug(const char* name);
    void sPtrDebug(const char* varName, std::shared_ptr<FaaRay::Base> sPtr, int index = -1);
    void sPtrDebug(const char* varName, std::shared_ptr<Bose> sPtr, int index = -1);
    void sPtrDebug(const char* varName, std::shared_ptr<unsigned char> sPtr, int index = -1);
};

#endif


