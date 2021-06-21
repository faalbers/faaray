#include "Base.hpp"
#include <iostream>

void Base::constructDebug(const char* name)
{
    #ifdef CLASS_DEBUG
    std::cout << "\n===> " << name << "\n";
    #endif
}

void Base::deconstructDebug(const char* name)
{
    #ifdef CLASS_DEBUG
    std::cout << "\n<=== " << name << "\n";
    #endif
}

void Base::sPtrDebug(const char* varName, std::shared_ptr<Base> sPtr, int index)
{
    #ifdef SHARED_POINTER_DEBUG
    if (index > -1)
        std::cout << "\n---- " << varName << "[" << index << "] use count = " << sPtr.use_count() - 1 << "\n";
    else
        std::cout << "\n---- " << varName << " use count = " << sPtr.use_count() - 1 << "\n";
    #endif
}