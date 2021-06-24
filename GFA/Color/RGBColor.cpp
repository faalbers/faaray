#include "RGBColor.hpp"
#include "Shared/Shared.hpp"

GFA::RGBColor::RGBColor()
    :   r(0.0),
        g(0.0),
        b(0.0),
        a(1.0)
{
}

GFA::RGBColor::RGBColor(
    const GFA::Scalar &gray_,
    const GFA::Scalar &a_)
    :   r(gray_),
        g(gray_),
        b(gray_),
        a(a_)
{
}

GFA::RGBColor::RGBColor(
    const GFA::Scalar &r_,
    const GFA::Scalar &g_,
    const GFA::Scalar &b_,
    const GFA::Scalar &a_)
    :   r(r_),
        g(g_),
        b(b_),
        a(a_)
{
}

GFA::RGBColor GFA::RGBColor::operator* (const GFA::Scalar &rhs) const
{
    return GFA::RGBColor(r * rhs, g * rhs, b * rhs, a * rhs);
}

GFA::RGBColor GFA::RGBColor::operator* (const GFA::RGBColor& rhs) const
{
    return GFA::RGBColor(r * rhs.r, g * rhs.g, b * rhs.b, a * rhs.a);
}

GFA::RGBColor & GFA::RGBColor::operator= (const GFA::RGBColor &rhs)
{
	r = rhs.r; g = rhs.g; b = rhs.b; a = rhs.a;

	return (*this);
}

GFA::RGBColor & GFA::RGBColor::operator+= (const GFA::RGBColor &rhs)
{
	r += rhs.r; g += rhs.g; b += rhs.b; a += rhs.a;

	return (*this);
}

GFA::RGBColor & GFA::RGBColor::operator/= (const GFA::Scalar &rhs)
{
	r /= rhs; g /= rhs; b /= rhs; a /= rhs;

	return (*this);
}

GFA::RGBColor & GFA::RGBColor::operator*= (const GFA::RGBColor &rhs)
{
	r *= rhs.r; g *= rhs.g; b *= rhs.b; a *= rhs.a;

	return (*this);
}

GFA::RGBColor & GFA::RGBColor::operator*= (const GFA::Scalar &rhs)
{
	r *= rhs; g *= rhs; b *= rhs; a *= rhs;

	return (*this);
}

std::ostream & GFA::operator<< (std::ostream &os, const GFA::RGBColor &rhs)
{
    os << "RGBColor(" << rhs.r << ", " << rhs.g << ", " << rhs.b << ", " << rhs.a << ")";
    return os;
}


