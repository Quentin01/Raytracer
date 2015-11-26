#pragma once

#include <vector>

#include "Object.hh"
#include "Utils/Ray.hh"
#include "Utils/Hit.hh"

class Tracer;

class Scene
{
public:
	Scene();
	Scene(Tracer *tracer);

	Scene(const Scene&) = delete;
	Scene(const Scene&&) = delete;

	virtual ~Scene();

	Scene						&operator=(const Scene&) = delete;

	void						setTracer(Tracer *t);
	Tracer						*getTracer() const;

	virtual void				addObject(const Object *object) = 0;

	virtual Hit::Type			intersectRay(const Ray &r, Hit &h) const = 0;

protected:
	Tracer						*_tracer;
};