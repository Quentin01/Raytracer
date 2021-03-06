#include <cmath>

#include "Scene.hh"
#include "Material/PhongMaterial.hh"

PhongMaterial::PhongMaterial(const Color &color) : 
    _ca(color), _cd(color), _cs(Color::white),
    _ka(0.1), _kd(0.5), _ks(0.4), _ns(10.0),
    _transparency(0.0), _reflection(0.0),
    _refractiveIndex(1.0)
{}

PhongMaterial::~PhongMaterial()
{}

void PhongMaterial::setCa(const Color &ca)
{
    _ca = ca;
}

Color PhongMaterial::getCa() const
{
    return (_ca);
}

void PhongMaterial::setCd(const Color &cd)
{
    _cd = cd;
}

Color PhongMaterial::getCd() const
{
    return (_cd);
}

void PhongMaterial::setCs(const Color &cs)
{
    _cs = cs;
}

Color PhongMaterial::getCs() const
{
    return (_cs);
}

void PhongMaterial::setKa(FLOAT ka)
{
    _ka = ka;
}

FLOAT PhongMaterial::getKa() const
{
    return (_ka);
}

void PhongMaterial::setKd(FLOAT kd)
{
    _kd = kd;
}

FLOAT PhongMaterial::getKd() const
{
    return (_kd);
}

void PhongMaterial::setKs(FLOAT ks)
{
    _ks = ks;
}

FLOAT PhongMaterial::getKs() const
{
    return (_ks);
}

void PhongMaterial::setNs(FLOAT ns)
{
    _ns = ns;
}

FLOAT PhongMaterial::getNs() const
{
    return (_ns);
}

void PhongMaterial::setTransparency(FLOAT transparency)
{
    _transparency = transparency;
}

FLOAT PhongMaterial::getTransparency() const
{
    return (_transparency);
}

void PhongMaterial::setReflection(FLOAT reflection)
{
    _reflection = reflection;
}

FLOAT PhongMaterial::getReflection() const
{
    return (_reflection);
}

void PhongMaterial::setRefractiveIndex(FLOAT refractiveIndex)
{
    _refractiveIndex = refractiveIndex;
}

FLOAT PhongMaterial::getRefractiveIndex() const
{
    return (_refractiveIndex);
}

Color PhongMaterial::shade(const Ray &r, const Hit &h) const
{
    Color   color = Color::black;

    // Ambient light
    if (getKa() > 0.0 && h.scene->getAmbientLight())
        color += getKa() * getCa() * h.scene->getAmbientLight()->getLight(h);

    auto &lights = h.scene->getLights();
    for (unsigned int i = 0, len = lights.size(); i < len; i++)
    {
        FLOAT   shade = lights[i]->getShade(h);

        if (shade > 0.0)
        {
            Vector3D    lightDirection = lights[i]->getDirection(h);
            Vector3D    normal = h.normal;

            lightDirection.normalize();
            normal.normalize();

            DOUBLE      dot = normal.dot(lightDirection);

            // Diffuse light
            if (getKd() > 0.0 && dot > 0.0)
                color += getKd() * getCd() * lights[i]->getLight(h) * shade * dot;

            // Specular light
            Vector3D    rayDirection = r.direction;
            Vector3D    reflRay = lightDirection - normal * lightDirection.dot(normal) * 2.0;

            rayDirection.normalize();
            reflRay.normalize();

            dot = reflRay.dot(rayDirection);

            if (getKs() > 0.0 && dot > 0.0)
                color += getKs() * getCs() * lights[i]->getLight(h) * shade * powf(dot, getNs());
        }
    }

    // TO-DO: Apply reflection
    // TO-DO: Apply refraction

    return (color);
}