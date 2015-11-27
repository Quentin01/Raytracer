#pragma once

#include "Object.hh"

class Sphere : public Object
{
public:
    Sphere(unsigned int radius, const Vector3D &position = Vector3D(0.0), const Material *material = nullptr);
    Sphere(const Sphere &o);
    Sphere(const Sphere &&o);

    virtual ~Sphere();

    Sphere          &operator=(const Sphere &o);

    void            setRadius(unsigned int radius);
    unsigned int    getRadius() const;

    virtual Hit::Type   intersectRay(const Ray &r, Hit &h, DOUBLE distMin) const;

protected:
    unsigned int    _radius;
};