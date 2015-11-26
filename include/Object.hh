#pragma once

#include "Material.hh"
#include "Utils/Hit.hh"

class Object
{
public:
	Object(const Vector3D &position = Vector3D(0.0), const Material *material = nullptr);
	Object(const Object &o);
	Object(const Object &&o);

	virtual ~Object();

	Object				&operator=(const Object &o);

	void				setMaterial(const Material *material);
	const Material		*getMaterial() const;

	void				setPosition(const Vector3D &position);
	Vector3D			getPosition() const;

	virtual Hit::Type	intersectRay(const Ray &r, Hit &h, DOUBLE distMin) const = 0;

protected:
	Vector3D			_position;
	const Material		*_material;
};