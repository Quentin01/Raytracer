#pragma once

#include "config.hh"

class Color
{
public: 
    Color();
    Color(FLOAT color);
    Color(FLOAT r, FLOAT g, FLOAT b);
    Color(const Color &c);
    Color(const Color &&c);
    virtual ~Color();

    Color   &operator=(const Color &c);

    Color   operator+(const Color &c) const;
    Color   &operator+=(const Color &c);

    Color   operator-(const Color &c) const;
    Color   &operator-=(const Color &c);

    Color   operator*(const FLOAT &rhs) const;
    Color   &operator*=(const FLOAT &rhs);

    Color   operator*(const Color &c) const;
    Color   &operator*=(const Color &c);

    Color   operator/(const FLOAT &rhs) const;
    Color   &operator/=(const FLOAT &rhs);

    FLOAT   r;
    FLOAT   g;
    FLOAT   b;

    static const Color  black;
    static const Color  white;
    static const Color  red;
    static const Color  green;
    static const Color  blue;
};