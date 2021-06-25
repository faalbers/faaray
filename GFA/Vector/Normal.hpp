
#ifndef __GFA_NORMAL_H__
#define __GFA_NORMAL_H__

#include "Shared/Shared.hpp"
#include "Vector3D.hpp"

namespace GFA {

class Normal : public GFA::Vector3D
{
    public:
        Normal();
        Normal(const GFA::Scalar &x_, const GFA::Scalar &y_, const GFA::Scalar &z_);
        Normal(const Vector3D &v);

        Normal &operator*=(const GFA::Scalar &rhs);
        Normal &operator/=(const GFA::Scalar &rhs);

};

std::ostream & operator<< (std::ostream &os, const Normal &rhs);

}

#endif


