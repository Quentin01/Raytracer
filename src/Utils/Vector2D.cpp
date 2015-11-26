#include <cmath>
#include "Utils/Vector2D.hh"

Vector2D::Vector2D() : x(0.0), y(0.0)
{}

Vector2D::Vector2D(DOUBLE x, DOUBLE y) : x(x), y(y)
{}

Vector2D::Vector2D(const Vector2D &v)
{
	x = v.x;
	y = v.y;
}

Vector2D::Vector2D(const Vector2D &&v)
{
	x = v.x;
	y = v.y;
}

Vector2D::~Vector2D()
{}

Vector2D &Vector2D::operator=(const Vector2D &v)
{
	x = v.x;
	y = v.y;

	return (*this);
}

Vector2D Vector2D::operator+(const Vector2D &v) const
{
	return Vector2D(x + v.x, y + v.y);
}

Vector2D &Vector2D::operator+=(const Vector2D &v)
{
	x += v.x;
	y += v.y;

	return (*this);
}

Vector2D Vector2D::operator-(const Vector2D &v) const
{
	return Vector2D(x - v.x, y - v.y);
}

Vector2D &Vector2D::operator-=(const Vector2D &v)
{
	x -= v.x;
	y -= v.y;

	return (*this);
}

Vector2D Vector2D::operator*(const DOUBLE &rhs) const
{
	return Vector2D(x * rhs, y * rhs);
}

Vector2D &Vector2D::operator*=(const DOUBLE &rhs)
{
	x *= rhs;
	y *= rhs;

	return (*this);
}

Vector2D Vector2D::operator/(const DOUBLE &rhs) const
{
	return Vector2D(x / rhs, y / rhs);
}

Vector2D &Vector2D::operator/=(const DOUBLE &rhs)
{
	x /= rhs;
	y /= rhs;

	return (*this);
}

DOUBLE Vector2D::getNorme() const
{
	return (sqrt(x * x + y * y));
}

void Vector2D::normalize()
{
	DOUBLE	norme = getNorme();

	if (norme > 0.0)
	{
		x /= norme;
		y /= norme;
	}
}