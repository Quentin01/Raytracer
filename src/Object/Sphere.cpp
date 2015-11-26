#include <cmath>

#include "Object/Sphere.hh"
#include "Utils/Ray.hh"

Sphere::Sphere(unsigned int radius, const Vector3D &position, const Material *material) : Object(position, material), _radius(radius)
{}

Sphere::Sphere(const Sphere &o) : Object(o)
{
	_radius = o._radius;
}

Sphere::Sphere(const Sphere &&o) : Object(o)
{
	_radius = o._radius;
}

Sphere::~Sphere()
{}

Sphere &Sphere::operator=(const Sphere &o)
{
	_position = o._position;
	_material = o._material;
	_radius = o._radius;

	return (*this);
}

void Sphere::setRadius(unsigned int radius)
{
	_radius = radius;
}

unsigned int Sphere::getRadius() const
{
	return (_radius);
}

Hit::Type Sphere::intersectRay(const Ray &r, Hit &h, DOUBLE distMin) const
{
	Vector3D	centerToOrigin = r.origin - _position;

	DOUBLE		a = r.direction.dot(r.direction);
	DOUBLE		b = 2.0 * centerToOrigin.dot(r.direction);
	DOUBLE		c = centerToOrigin.dot(centerToOrigin) - _radius * _radius;
	DOUBLE		delta = b * b - 4.0 * a * c;

	DOUBLE		smallDist;
	DOUBLE		bigDist;

	if (delta < 0.0)
		return (Hit::NONE);
	else
	{
		DOUBLE	sqrtDelta = sqrt(delta);

		smallDist = (-b - sqrtDelta) / (2.0 * a);
		bigDist = (-b + sqrtDelta) / (2.0 * a);

		if (smallDist > EPSILON)
		{
			if (smallDist >= distMin)
				return (Hit::NONE);

			h.localPoint = r.origin + r.direction * smallDist;
			h.normal = centerToOrigin;
			h.normal.normalize();

			return (Hit::OUTSIDE);
		}

		if (bigDist > EPSILON)
		{
			if (bigDist >= distMin)
				return (Hit::NONE);

			h.localPoint = r.origin + r.direction * bigDist;
			h.normal = centerToOrigin;
			h.normal.normalize();
			
			if (smallDist < 0.0)
				return (Hit::INSIDE);
			else
				return (Hit::OUTSIDE);
		}
	}

	return (Hit::NONE);
}