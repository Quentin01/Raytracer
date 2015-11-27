#pragma once

#include "Utils/Vector3D.hh"

class Scene;
class Material;
class Ray;

class Hit
{
public:
    enum Type
    {
        NONE,
        INSIDE,
        OUTSIDE
    };

    Hit();
    Hit(const Hit &h);
    Hit(const Hit &&h);

    virtual ~Hit();

    Hit             &operator=(const Hit &h);

    Hit::Type       type;

    const Scene     *scene;
    const Material  *material;

    Vector3D        point;
    Vector3D        localPoint;

    Vector3D        normal;

    const Ray       *ray;
    unsigned int    depth;
    DOUBLE          dist;
    DOUBLE          t;
};