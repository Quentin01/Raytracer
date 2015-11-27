#include "Light/AmbientLight.hh"

AmbientLight::AmbientLight(const Color &color, FLOAT intensity) : _intensity(intensity), _color(color)
{}

AmbientLight::~AmbientLight()
{}

void AmbientLight::setIntensity(FLOAT intensity)
{
    _intensity = intensity;
}

FLOAT AmbientLight::getIntensity() const
{
    return (_intensity);
}

void AmbientLight::setColor(const Color& color)
{
    _color = color;
}

void AmbientLight::setColor(FLOAT r, FLOAT g, FLOAT b)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;
}

Color AmbientLight::getColor() const
{
    return (_color);
}

FLOAT AmbientLight::getShade(const Hit &h) const
{
    (void)(h);
    return (1.0);
}

Vector3D AmbientLight::getDirection(const Hit &h) const
{
    (void)(h);
    return (Vector3D(0.0));
}

Color AmbientLight::getLight(const Hit &h) const
{
    (void)(h);
    return (_color * _intensity);
}