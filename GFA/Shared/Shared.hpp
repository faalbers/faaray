#ifndef __GFA_SHARED_H__
#define __GFA_SHARED_H__

namespace GFA {
typedef double          Scalar;
typedef unsigned int    Index;
typedef unsigned int    Size;

const Scalar EPSILON        = 0.0001; // very small
const Scalar HUGE_SCALAR    = 1.0E10; // very large
const Scalar PI = 3.14159265359;
const Scalar invPI = 1.0 / PI;
}

#endif

