#pragma once

#include "Light.hh"

class PointLight : public Light
{
public:
    PointLight(const Vector3D &position = Vector3D(), const Color &color = Color::white, FLOAT intensity = 1.0);

    virtual ~PointLight();

    void                setIntensity(FLOAT intensity);
    FLOAT               getIntensity() const;

    void                setColor(const Color &color);
    void                setColor(FLOAT r, FLOAT g, FLOAT b);
    Color               getColor() const;

    void                setPosition(const Vector3D &position);
    void                setPosition(DOUBLE x, DOUBLE y, DOUBLE z);
    Vector3D            getPosition() const;

    virtual FLOAT       getShade(const Hit &h) const;
    virtual Vector3D    getDirection(const Hit &h) const;
    virtual Color       getLight(const Hit &h) const;

protected:
    FLOAT               _intensity;
    Color               _color;
    Vector3D            _position;
};