#pragma once

#include "Light.hh"

class AmbientLight : public Light
{
public:
    AmbientLight(const Color &color = Color::white, FLOAT intensity = 1.0);

    virtual ~AmbientLight();

    void                setIntensity(FLOAT intensity);
    FLOAT               getIntensity() const;

    void                setColor(const Color& color);
    void                setColor(FLOAT r, FLOAT g, FLOAT b);
    Color               getColor() const;

    virtual FLOAT       getShade(const Hit &h) const;
    virtual Vector3D    getDirection(const Hit &h) const;
    virtual Color       getLight(const Hit &h) const;

protected:
    FLOAT               _intensity;
    Color               _color;
};