#include <cmath>

#include "Object/Sphere.hh"
#include "Utils/Ray.hh"

Sphere::Sphere(unsigned int radius, const Vector3D &position, const Material *material) : Object(position, material), _radius(radius)
{}

Sphere::Sphere(const Sphere &o) : Object(o)
{
    _radius = o._radius;
}

Sphere::Sphere(const Sphere &&o) : Object(o)
{
    _radius = o._radius;
}

Sphere::~Sphere()
{}

Sphere &Sphere::operator=(const Sphere &o)
{
    _position = o._position;
    _material = o._material;
    _radius = o._radius;

    return (*this);
}

void Sphere::setRadius(unsigned int radius)
{
    _radius = radius;
}

unsigned int Sphere::getRadius() const
{
    return (_radius);
}

bool Sphere::intersectRay(const Ray &r, Hit &h, DOUBLE distMin) const
{
    Vector3D    centerToOrigin = r.origin - _position;

    DOUBLE      a = r.direction.dot(r.direction);
    DOUBLE      b = 2.0 * centerToOrigin.dot(r.direction);
    DOUBLE      c = centerToOrigin.dot(centerToOrigin) - _radius * _radius;
    DOUBLE      delta = b * b - 4.0 * a * c;

    if (delta < 0.0)
        return (false);
    else
    {
        DOUBLE  sqrtDelta = sqrt(delta);

        DOUBLE  smallDist = (-b - sqrtDelta) / (2.0 * a);
        DOUBLE  bigDist = (-b + sqrtDelta) / (2.0 * a);

        if (smallDist > EPSILON)
        {
            if (smallDist > distMin)
                return (false);

            h.t = smallDist;
            h.localPoint = r.origin + r.direction * h.t;
            h.normal = centerToOrigin;
            h.normal.normalize();
            h.type = Hit::OUTSIDE;

            return (true);
        }

        if (bigDist > EPSILON)
        {
            if (bigDist > distMin)
                return (Hit::NONE);

            h.t = bigDist;
            h.localPoint = r.origin + r.direction * h.t;
            h.normal = centerToOrigin;
            h.normal.normalize();
            
            if (smallDist < 0.0)
                 h.type = Hit::INSIDE;
            else
                 h.type = Hit::OUTSIDE;
        
            return (true);
        }
    }

    return (false);
}