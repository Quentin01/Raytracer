#include "Scene.hh"
#include "Tracer.hh"

Scene::Scene() : Scene(nullptr)
{}

Scene::Scene(Tracer *tracer) : _tracer(tracer), _ambientLight(nullptr)
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

void Scene::setAmbientLight(const Light *light)
{
    _ambientLight = light;
}

const Light *Scene::getAmbientLight() const
{
    return (_ambientLight);
}

void Scene::addLight(const Light *light)
{
    _lights.push_back(light);
}

const std::vector<const Light*> &Scene::getLights() const
{
    return (_lights);
}