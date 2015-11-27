#pragma once

#include "config.hh"

class Vector2D
{
public: 
    Vector2D();
    Vector2D(DOUBLE x, DOUBLE y);
    Vector2D(const Vector2D &v);
    Vector2D(const Vector2D &&v);
    
    virtual ~Vector2D();

    Vector2D    &operator=(const Vector2D &v);

    Vector2D    operator+(const Vector2D &v) const;
    Vector2D    &operator+=(const Vector2D &v);

    Vector2D    operator-(const Vector2D &v) const;
    Vector2D    &operator-=(const Vector2D &v);

    Vector2D    operator*(const DOUBLE &rhs) const;
    Vector2D    &operator*=(const DOUBLE &rhs);

    Vector2D    operator/(const DOUBLE &rhs) const;
    Vector2D    &operator/=(const DOUBLE &rhs);

    DOUBLE      getNorme() const;
    void        normalize();

    DOUBLE  x;
    DOUBLE  y;
};