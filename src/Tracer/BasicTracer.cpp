#include <limits>

#include "Tracer/BasicTracer.hh"
#include "Scene.hh"
#include "Utils/Hit.hh"

Color BasicTracer::traceRay(const Ray &r, unsigned int depth) const
{
	Hit	h;

	h.dist = std::numeric_limits<DOUBLE>::infinity();
	if (_scene && _scene->intersectRay(r, h) != Hit::NONE)
	{
		h.ray = &r;
		h.depth = depth;
		h.dist = (r.origin - h.point).getNorme();
		return (h.material->shade(r, h));
	}
	else
		return (Color::black);
}