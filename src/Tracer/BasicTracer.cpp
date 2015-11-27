#include "Tracer/BasicTracer.hh"
#include "Scene.hh"
#include "Utils/Hit.hh"

Color BasicTracer::traceRay(const Ray &r, Hit &h, unsigned int depth) const
{
    if (_scene && _scene->intersectRay(r, h))
    {
        h.scene = _scene;
        h.ray = &r;
        h.depth = depth;
        h.point = r.origin + r.direction * h.t;
        h.dist = (r.origin - h.point).getNorme();
        return (h.material->shade(r, h));
    }
    else
    {
        h.type = Hit::NONE;
        return (Color::black);
    }
}