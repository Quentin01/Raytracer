#include <cmath>
#include "Utils/Vector3D.hh"

Vector3D::Vector3D() : Vector3D(0.0)
{}

Vector3D::Vector3D(DOUBLE v) : x(v), y(v), z(v) 
{}

Vector3D::Vector3D(DOUBLE x, DOUBLE y, DOUBLE z) : x(x), y(y), z(z) 
{}

Vector3D::Vector3D(const Vector3D &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3D::Vector3D(const Vector3D &&v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3D::~Vector3D()
{}

Vector3D &Vector3D::operator=(const Vector3D &v)
{
    x = v.x;
    y = v.y;
    z = v.z;

    return (*this);
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D &Vector3D::operator+=(const Vector3D &v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return (*this);
}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

Vector3D &Vector3D::operator-=(const Vector3D &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return (*this);
}

Vector3D Vector3D::operator*(const DOUBLE &rhs) const
{
    return Vector3D(x * rhs, y * rhs, z * rhs);
}

Vector3D &Vector3D::operator*=(const DOUBLE &rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;

    return (*this);
}

Vector3D Vector3D::operator/(const DOUBLE &rhs) const
{
    return Vector3D(x / rhs, y / rhs, z / rhs);
}

Vector3D &Vector3D::operator/=(const DOUBLE &rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;

    return (*this);
}

Vector3D Vector3D::operator*(const Vector3D &v) const
{
    return (Vector3D(x * v.x, y * v.y, z * v.z));
}

Vector3D    &Vector3D::operator*=(const Vector3D &v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return (*this);
}

DOUBLE Vector3D::dot(const Vector3D &v) const
{
    return (x * v.x + y * v.y + z * v.z);
}

Vector3D Vector3D::cross(const Vector3D &v) const
{
    return (Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}

DOUBLE Vector3D::getNorme() const
{
    return (sqrt(x * x + y * y + z * z));
}

void Vector3D::normalize()
{
    DOUBLE  norme = getNorme();

    if (norme > 0.0)
    {
        x /= norme;
        y /= norme;
        z /= norme;
    }
}