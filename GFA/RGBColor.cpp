#include "RGBColor.hpp"

RGBColor::RGBColor()
    :   r(0.0),
        g(0.0),
        b(0.0),
        a(1.0)
{
}

RGBColor::RGBColor(
    const Scalar &gray_,
    const Scalar &a_)
    :   r(gray_),
        g(gray_),
        b(gray_),
        a(a_)
{
}

RGBColor::RGBColor(
    const Scalar &r_,
    const Scalar &g_,
    const Scalar &b_,
    const Scalar &a_)
    :   r(r_),
        g(g_),
        b(b_),
        a(a_)
{
}

RGBColor RGBColor::operator* (const Scalar &rhs) const
{
    return RGBColor(r * rhs, g * rhs, b * rhs, a * rhs);
}

RGBColor RGBColor::operator* (const RGBColor& rhs) const
{
    return RGBColor(r * rhs.r, g * rhs.g, b * rhs.b, a * rhs.a);
}

RGBColor & RGBColor::operator= (const RGBColor &rhs)
{
	r = rhs.r; g = rhs.g; b = rhs.b; a = rhs.a;

	return (*this);
}

RGBColor & RGBColor::operator+= (const RGBColor &rhs)
{
	r += rhs.r; g += rhs.g; b += rhs.b; a += rhs.a;

	return (*this);
}

RGBColor & RGBColor::operator/= (const Scalar &rhs)
{
	r /= rhs; g /= rhs; b /= rhs; a /= rhs;

	return (*this);
}

RGBColor & RGBColor::operator*= (const RGBColor &rhs)
{
	r *= rhs.r; g *= rhs.g; b *= rhs.b; a *= rhs.a;

	return (*this);
}

RGBColor & RGBColor::operator*= (const Scalar &rhs)
{
	r *= rhs; g *= rhs; b *= rhs; a *= rhs;

	return (*this);
}

std::ostream & operator<< (std::ostream &os, const RGBColor &rhs)
{
    os << "RGBColor(" << rhs.r << ", " << rhs.g << ", " << rhs.b << ", " << rhs.a << ")";
    return os;
}


