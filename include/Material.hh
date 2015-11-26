#pragma once

#include "Utils/Color.hh"
#include "Utils/Hit.hh"
#include "Utils/Ray.hh"

class Material
{
public:
	Material();

	virtual ~Material();

	virtual Color	shade(const Ray &r, const Hit &h) const = 0;
};