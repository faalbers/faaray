#ifndef _FAARAY_UTILS_H__
#define _FAARAY_UTILS_H__

#include "Shared/Shared.hpp"

#include <random>

// Random setup
typedef std::mt19937 MyRNG;
//typedef std::default_random_engine MyRNG;

// Debug setting
const bool LOG_DEBUG = false;

class Error : public std::exception
{
public:
    Error(void);
    Error(const char *procName);
    Error(const char *_procName, const char *msg);
    const char * what(const char *msg) const throw ();
};

#endif

