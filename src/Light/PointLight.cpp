#include "Light/PointLight.hh"

PointLight::PointLight(const Vector3D &position, const Color &color, FLOAT intensity) : _intensity(intensity), _color(color), _position(position)
{}

PointLight::~PointLight()
{}

void PointLight::setIntensity(FLOAT intensity)
{
    _intensity = intensity;
}

FLOAT PointLight::getIntensity() const
{
    return (_intensity);
}

void PointLight::setColor(const Color& color)
{
    _color = color;
}

void PointLight::setColor(FLOAT r, FLOAT g, FLOAT b)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;
}

Color PointLight::getColor() const
{
    return (_color);
}

void PointLight::setPosition(const Vector3D &position)
{
    _position = position;
}

void PointLight::setPosition(DOUBLE x, DOUBLE y, DOUBLE z)
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
}

Vector3D PointLight::getPosition() const
{
    return (_position);
}

FLOAT PointLight::getShade(const Hit &h) const
{
    (void)(h);
    return (1.0);
}

Vector3D PointLight::getDirection(const Hit &h) const
{
    return (_position - h.point);
}

Color PointLight::getLight(const Hit &h) const
{
    (void)(h);
    return (_color * _intensity);
}