#include "Object/Plane.hh"
#include "Utils/Ray.hh"

Plane::Plane(const Vector3D &position, const Vector3D &normal, const Material *material) : Object(position, material), _normal(normal)
{}

Plane::Plane(const Plane &o) : Object(o)
{
    _normal = o._normal;
}

Plane::Plane(const Plane &&o) : Object(o)
{
    _normal = o._normal;
}

Plane::~Plane()
{}

Plane &Plane::operator=(const Plane &o)
{
    _position = o._position;
    _material = o._material;
    _normal = o._normal;

    return (*this);
}

void Plane::setNormal(const Vector3D &normal)
{
    _normal = normal;
    _normal.normalize();
}

Vector3D Plane::getNormal() const
{
    return (_normal);
}

bool Plane::intersectRay(const Ray &r, Hit &h, DOUBLE distMin) const
{
    DOUBLE t = (_position - r.origin).dot(_normal) / r.direction.dot(_normal);

    if (t > EPSILON && t < distMin)
    {
        h.t = t;
        h.localPoint = r.origin + r.direction * h.t;
        h.normal = _normal;
        h.type = Hit::OUTSIDE;

        return (true);
    }

    return (false);
}