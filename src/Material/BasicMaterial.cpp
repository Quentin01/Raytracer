#include "Scene.hh"
#include "Material/BasicMaterial.hh"

BasicMaterial::BasicMaterial(const Color &color) : _color(color)
{}

BasicMaterial::~BasicMaterial()
{}

Color BasicMaterial::shade(const Ray &r, const Hit &h) const
{
    (void)(r);
    (void)(h);

    return (_color);
}