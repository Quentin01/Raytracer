#pragma once

#include "Object.hh"

class Plane : public Object
{
public:
    Plane(const Vector3D &position = Vector3D(0.0), const Vector3D &normal = Vector3D(0.0, -1.0, 0.0), const Material *material = nullptr);
    Plane(const Plane &o);
    Plane(const Plane &&o);

    virtual ~Plane();

    Plane           &operator=(const Plane &o);

    void            setNormal(const Vector3D &normal);
    Vector3D        getNormal() const;

    virtual bool    intersectRay(const Ray &r, Hit &h, DOUBLE distMin) const;

protected:
    Vector3D        _normal;
};