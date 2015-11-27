#pragma once

#include "Material.hh"

class PhongMaterial : public Material
{
public:
    PhongMaterial(const Color &color = Color::white);

    virtual ~PhongMaterial();

    void            setCa(const Color &ca);
    Color           getCa() const;

    void            setCd(const Color &cd);
    Color           getCd() const;

    void            setCs(const Color &cs);
    Color           getCs() const;

    void            setKa(FLOAT ka);
    FLOAT           getKa() const;

    void            setKd(FLOAT kd);
    FLOAT           getKd() const;

    void            setKs(FLOAT ks);
    FLOAT           getKs() const;

    void            setNs(FLOAT ns);
    FLOAT           getNs() const;

    void            setTransparency(FLOAT transparency);
    FLOAT           getTransparency() const;

    void            setReflection(FLOAT reflection);
    FLOAT           getReflection() const;

    void            setRefractiveIndex(FLOAT refractiveIndex);
    FLOAT           getRefractiveIndex() const;

    virtual Color   shade(const Ray &r, const Hit &h) const;

protected:
    Color           _ca; // Ambient color
    Color           _cd; // Diffuse color
    Color           _cs; // Specular color

    FLOAT           _ka; // Ambient factor
    FLOAT           _kd; // Diffuse factor
    FLOAT           _ks; // Specular factor
    FLOAT           _ns; // Specular exponent

    FLOAT           _transparency; // Transparency factor
    FLOAT           _reflection; // Reflection factor

    FLOAT           _refractiveIndex; // Refractive index
};