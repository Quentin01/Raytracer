#include "Utils/Ray.hh"

Ray::Ray()
{}

Ray::Ray(Vector3D origin, Vector3D direction) : origin(origin), direction(direction), refractiveIndex(1.0)
{}

Ray::Ray(const Ray &r)
{
    origin = r.origin;
    direction = r.direction;
    refractiveIndex = r.refractiveIndex;
}

Ray::Ray(const Ray &&r)
{
    origin = r.origin;
    direction = r.direction;
    refractiveIndex = r.refractiveIndex;
}

Ray::~Ray()
{}

Ray &Ray::operator=(const Ray &r)
{
    origin = r.origin;
    direction = r.direction;
    refractiveIndex = r.refractiveIndex;

    return (*this);
}