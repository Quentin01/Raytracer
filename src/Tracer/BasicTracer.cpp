#include <limits>

#include "Tracer/BasicTracer.hh"
#include "Scene.hh"
#include "Utils/Hit.hh"

Color BasicTracer::traceRay(const Ray &r, Hit &h, unsigned int depth) const
{
    h.dist = std::numeric_limits<DOUBLE>::infinity();
    if (_scene && _scene->intersectRay(r, h))
    {
        h.scene = _scene;
        h.ray = &r;
        h.depth = depth;
        h.dist = (r.origin - h.point).getNorme();
        return (h.material->shade(r, h));
    }
    else
    {
        h.type = Hit::NONE;
        return (Color::black);
    }
}