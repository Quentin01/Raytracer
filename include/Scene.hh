#pragma once

#include <vector>

#include "Object.hh"
#include "Light.hh"
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

	Scene									&operator=(const Scene&) = delete;

	void									setTracer(Tracer *t);
	Tracer									*getTracer() const;

	virtual void							setAmbientLight(const Light *light);
	virtual const Light						*getAmbientLight() const;

	virtual void							addLight(const Light *light);
	virtual const std::vector<const Light*>	&getLights() const;

	virtual void							addObject(const Object *object) = 0;

	virtual Hit::Type						intersectRay(const Ray &r, Hit &h) const = 0;

protected:
	Tracer									*_tracer;

	const Light								*_ambientLight;
	std::vector<const Light*>				_lights;
};