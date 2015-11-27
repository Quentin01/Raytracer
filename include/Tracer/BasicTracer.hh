#pragma once

#include "Tracer.hh"

class BasicTracer : public Tracer
{
public:
    virtual Color   traceRay(const Ray &r, Hit &h, unsigned int depth = 0) const;
};