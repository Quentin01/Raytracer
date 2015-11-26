#include "Utils/Hit.hh"

Hit::Hit()
{}

Hit::Hit(const Hit &h)
{
	point = h.point;
	localPoint = h.localPoint;
	normal = h.normal;
	ray = h.ray;
	depth = h.depth;
	dist = h.dist;
}

Hit::Hit(const Hit &&h)
{
	point = h.point;
	localPoint = h.localPoint;
	normal = h.normal;
	ray = h.ray;
	depth = h.depth;
	dist = h.dist;
}

Hit::~Hit()
{}

Hit	&Hit::operator=(const Hit &h)
{
	point = h.point;
	localPoint = h.localPoint;
	normal = h.normal;
	ray = h.ray;
	depth = h.depth;
	dist = h.dist;

	return (*this);
}