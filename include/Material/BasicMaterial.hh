#pragma once

#include "Material.hh"

class BasicMaterial : public Material
{
public:
    BasicMaterial(const Color &color);

    virtual ~BasicMaterial();

    virtual Color   shade(const Ray &r, const Hit &h) const;

protected:
    Color           _color;
};