#include "Tracer.hh"
#include "Scene.hh"

Tracer::Tracer() : _scene(nullptr)
{}

Tracer::Tracer(Scene *scene) : _scene(scene)
{}

Tracer::Tracer(const Tracer &t)
{
    _scene = t._scene;
}

Tracer::Tracer(const Tracer &&t)
{
    _scene = t._scene;
}

Tracer::~Tracer()
{}

Tracer &Tracer::operator=(const Tracer &t)
{
    _scene = t._scene;

    return (*this);
}

void Tracer::setScene(Scene *scene)
{
    _scene = scene;
}

Scene *Tracer::getScene() const
{
    return (_scene);
}

Color Tracer::traceRay(const Ray &r, unsigned int depth) const
{
    Hit h;
    
    return (traceRay(r, h, depth));
}