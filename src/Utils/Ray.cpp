#include "Utils/Ray.hh"

Ray::Ray()
{}

Ray::Ray(Vector3D origin, Vector3D direction) : origin(origin), direction(direction)
{}

Ray::Ray(const Ray &r)
{
	origin = r.origin;
	direction = r.direction;
}

Ray::Ray(const Ray &&r)
{
	origin = r.origin;
	direction = r.direction;
}

Ray::~Ray()
{}

Ray &Ray::operator=(const Ray &r)
{
	origin = r.origin;
	direction = r.direction;

	return (*this);
}