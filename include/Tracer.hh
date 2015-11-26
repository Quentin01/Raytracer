#pragma once

#include "Utils/Color.hh"
#include "Utils/Ray.hh"

class Scene;

class Tracer
{
public:
	Tracer();
	Tracer(Scene *scene);

	Tracer(const Tracer &t);
	Tracer(const Tracer &&t);

	virtual ~Tracer();

	Tracer			&operator=(const Tracer &t);

	void			setScene(Scene *scene);
	Scene			*getScene() const;

	virtual Color	traceRay(const Ray &r, unsigned int depth = 0) const = 0;

protected:
	Scene		*_scene;
};