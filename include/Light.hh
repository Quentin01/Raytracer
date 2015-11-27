#pragma once

#include "Utils/Vector3D.hh"
#include "Utils/Color.hh"
#include "Utils/Hit.hh"

class Light
{
public:
    Light();

    virtual ~Light();

    virtual Vector3D    getDirection(const Hit &h) const = 0;
    virtual Color       getLight(const Hit &h) const = 0;
};