#include <limits>

#include "Utils/Hit.hh"

Hit::Hit()
{
    t = std::numeric_limits<DOUBLE>::infinity();
    dist = std::numeric_limits<DOUBLE>::infinity();
}

Hit::Hit(const Hit &h)
{
    type = h.type;
    scene = h.scene;
    point = h.point;
    localPoint = h.localPoint;
    normal = h.normal;
    ray = h.ray;
    depth = h.depth;
    dist = h.dist;
    t = h.t;
}

Hit::Hit(const Hit &&h)
{
    type = h.type;
    scene = h.scene;
    point = h.point;
    localPoint = h.localPoint;
    normal = h.normal;
    ray = h.ray;
    depth = h.depth;
    dist = h.dist;
    t = h.t;
}

Hit::~Hit()
{}

Hit &Hit::operator=(const Hit &h)
{
    type = h.type;
    scene = h.scene;
    point = h.point;
    localPoint = h.localPoint;
    normal = h.normal;
    ray = h.ray;
    depth = h.depth;
    dist = h.dist;
    t = h.t;

    return (*this);
}