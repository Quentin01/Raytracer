#pragma once

#include "Scene.hh"

class BasicScene : public Scene
{
public:
	using Scene::Scene;
	
	virtual void				addObject(const Object *object);
	virtual Hit::Type			intersectRay(const Ray &r, Hit &h) const;

protected:
	std::vector<const Object*>	_objects;
};