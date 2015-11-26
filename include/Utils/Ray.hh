#pragma once

#include "Utils/Vector3D.hh"

class Ray
{
public:
	Ray();
	Ray(Vector3D origin, Vector3D direction);
	Ray(const Ray &r);
	Ray(const Ray &&r);

	virtual ~Ray();

	Ray			&operator=(const Ray &r);

	Vector3D	origin;
	Vector3D	direction;
};