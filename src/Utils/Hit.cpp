#include "Utils/Hit.hh"

Hit::Hit()
{}

Hit::Hit(const Hit &h)
{
	scene = h.scene;
	point = h.point;
	localPoint = h.localPoint;
	normal = h.normal;
	ray = h.ray;
	depth = h.depth;
	dist = h.dist;
	t = h.t;
}

Hit::Hit(const Hit &&h)
{
	scene = h.scene;
	point = h.point;
	localPoint = h.localPoint;
	normal = h.normal;
	ray = h.ray;
	depth = h.depth;
	dist = h.dist;
	t = h.t;
}

Hit::~Hit()
{}

Hit	&Hit::operator=(const Hit &h)
{
	scene = h.scene;
	point = h.point;
	localPoint = h.localPoint;
	normal = h.normal;
	ray = h.ray;
	depth = h.depth;
	dist = h.dist;
	t = h.t;

	return (*this);
}