#pragma once

#include "Object.hh"

class Torus : public Object
{
public:
    Torus(unsigned int innerRadius, unsigned int tubeRadius, const Vector3D &position = Vector3D(0.0), const Material *material = nullptr);
    Torus(const Torus &o);
    Torus(const Torus &&o);

    virtual ~Torus();

    Torus           &operator=(const Torus &o);

    void            setInnerRadius(unsigned int innerRadius);
    unsigned int    getInnerRadius() const;

    void            setTubeRadius(unsigned int tubeRadius);
    unsigned int    getTubeRadius() const;

    virtual bool    intersectRay(const Ray &r, Hit &h, DOUBLE tMin) const;

protected:
    unsigned int    _innerRadius;
    unsigned int    _tubeRadius;
};