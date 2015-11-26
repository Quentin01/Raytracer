#include "Scene.hh"
#include "Tracer.hh"

Scene::Scene() : _tracer(nullptr)
{}

Scene::Scene(Tracer *tracer) : _tracer(tracer)
{
	_tracer->setScene(this);
}

Scene::~Scene()
{}

void Scene::setTracer(Tracer *t)
{
	_tracer = t;
	_tracer->setScene(this);
}

Tracer *Scene::getTracer() const
{
	return (_tracer);
}