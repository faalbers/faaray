#include "Bose.hpp"
#include <iostream>

void Bose::constructDebug(const char* name)
{
    #ifdef CLASS_DEBUG
    std::cout << "\n===> " << name << "\n";
    #endif
}

void Bose::deconstructDebug(const char* name)
{
    #ifdef CLASS_DEBUG
    std::cout << "\n<=== " << name << "\n";
    #endif
}

void Bose::sPtrDebug(const char* varName, std::shared_ptr<Bose> sPtr, int index)
{
    #ifdef SHARED_POINTER_DEBUG
    if (index > -1)
        std::cout << "\n---- " << varName << "[" << index << "] use count = " << sPtr.use_count() - 1 << "\n";
    else
        std::cout << "\n---- " << varName << " use count = " << sPtr.use_count() - 1 << "\n";
    #endif
}

void Bose::sPtrDebug(const char* varName, std::shared_ptr<FaaRay::Base> sPtr, int index)
{
    #ifdef SHARED_POINTER_DEBUG
    if (index > -1)
        std::cout << "\n---- " << varName << "[" << index << "] use count = " << sPtr.use_count() - 1 << "\n";
    else
        std::cout << "\n---- " << varName << " use count = " << sPtr.use_count() - 1 << "\n";
    #endif
}

void Bose::sPtrDebug(const char* varName, std::shared_ptr<unsigned char> sPtr, int index)
{
    #ifdef SHARED_POINTER_DEBUG
    if (index > -1)
        std::cout << "\n---- " << varName << "[" << index << "] use count = " << sPtr.use_count() - 1 << "\n";
    else
        std::cout << "\n---- " << varName << " use count = " << sPtr.use_count() - 1 << "\n";
    #endif
}