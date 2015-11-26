#include "Utils/Color.hh"

const Color	Color::black(0.0);
const Color	Color::white(1.0);
const Color	Color::red(1.0, 0.0, 0.0);
const Color	Color::green(0.0, 1.0, 0.0);
const Color	Color::blue(0.0, 0.0, 1.0);

Color::Color() : r(0.0), g(0.0), b(0.0) 
{}

Color::Color(FLOAT color) : r(color), g(color), b(color) 
{}

Color::Color(FLOAT r, FLOAT g, FLOAT b) : r(r), g(g), b(b) 
{}

Color::Color(const Color &c)
{
	r = c.r;
	g = c.g;
	b = c.b;
}

Color::Color(const Color &&c)
{
	r = c.r;
	g = c.g;
	b = c.b;
}

Color::~Color()
{}

Color &Color::operator=(const Color &c)
{
	r = c.r;
	g = c.g;
	b = c.b;
	
	return (*this);
}

Color Color::operator+(const Color &v) const
{
	return Color(r + v.r, g + v.g, b + v.b);
}

Color &Color::operator+=(const Color &v)
{
	r += v.r;
	g += v.g;
	b += v.b;

	return (*this);
}

Color Color::operator-(const Color &v) const
{
	return Color(r - v.r, g - v.g, b - v.b);
}

Color &Color::operator-=(const Color &v)
{
	r -= v.r;
	g -= v.g;
	b -= v.b;

	return (*this);
}

Color Color::operator*(const FLOAT &rhs) const
{
	return Color(r * rhs, g * rhs, b * rhs);
}

Color &Color::operator*=(const FLOAT &rhs)
{
	r *= rhs;
	g *= rhs;
	b *= rhs;

	return (*this);
}

Color Color::operator/(const FLOAT &rhs) const
{
	return Color(r / rhs, g / rhs, b / rhs);
}

Color &Color::operator/=(const FLOAT &rhs)
{
	r /= rhs;
	g /= rhs;
	b /= rhs;

	return (*this);
}