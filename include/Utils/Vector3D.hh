#pragma once

#include "config.hh"

class Vector3D
{
public: 
    Vector3D();
    Vector3D(DOUBLE v);
    Vector3D(DOUBLE x, DOUBLE y, DOUBLE z);
    Vector3D(const Vector3D &v);
    Vector3D(const Vector3D &&v);
    
    virtual ~Vector3D();

    Vector3D    &operator=(const Vector3D &v);

    Vector3D    operator+(const Vector3D &v) const;
    Vector3D    &operator+=(const Vector3D &v);

    Vector3D    operator-(const Vector3D &v) const;
    Vector3D    &operator-=(const Vector3D &v);

    Vector3D    operator*(const DOUBLE &rhs) const;
    Vector3D    &operator*=(const DOUBLE &rhs);

    Vector3D    operator/(const DOUBLE &rhs) const;
    Vector3D    &operator/=(const DOUBLE &rhs);

    Vector3D    operator*(const Vector3D &v) const;
    Vector3D    &operator*=(const Vector3D &v);

    DOUBLE      dot(const Vector3D &v) const;
    Vector3D    cross(const Vector3D &v) const;

    DOUBLE      getNorme() const;
    void        normalize();

    DOUBLE  x;
    DOUBLE  y;
    DOUBLE  z;
};