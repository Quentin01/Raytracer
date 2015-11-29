#include <limits>

#include "Utils/Math.hh"
#include "Object/Torus.hh"

Torus::Torus(unsigned int innerRadius, unsigned int tubeRadius, const Vector3D &position, const Material *material) : Object(position, material), _innerRadius(innerRadius), _tubeRadius(tubeRadius)
{}

Torus::Torus(const Torus &o) : Object(o)
{
    _innerRadius = o._innerRadius;
    _tubeRadius = o._tubeRadius;
}

Torus::Torus(const Torus &&o) : Object(o)
{
    _innerRadius = o._innerRadius;
    _tubeRadius = o._tubeRadius;
}

Torus::~Torus()
{}

Torus &Torus::operator=(const Torus &o)
{
    _position = o._position;
    _material = o._material;
    _innerRadius = o._innerRadius;
    _tubeRadius = o._tubeRadius;

    return (*this);
}

void Torus::setInnerRadius(unsigned int innerRadius)
{
    _innerRadius = innerRadius;
}

unsigned int Torus::getInnerRadius() const
{
    return (_innerRadius);
}

void Torus::setTubeRadius(unsigned int tubeRadius)
{
    _tubeRadius = tubeRadius;
}

unsigned int Torus::getTubeRadius() const
{
    return (_tubeRadius);
}

bool Torus::intersectRay(const Ray &r, Hit &h, DOUBLE tMin) const
{
    Vector3D    origin = r.origin - _position;

    DOUBLE  xo = origin.x, yo = origin.y, zo = origin.z;
    DOUBLE  xd = r.direction.x, yd = r.direction.y, zd = r.direction.z;

    DOUBLE  coeffs[5];
    DOUBLE  roots[4];

    DOUBLE  sum_d_sqrd = xd * xd + yd * yd + zd * zd;
    DOUBLE  e = xo * xo + yo * yo + zo * zo - _innerRadius * _innerRadius - _tubeRadius * _tubeRadius;
    DOUBLE  f = xo * xd + yo * yd + zo * zd;
    DOUBLE  four_a_sqrd = 4.0 * _innerRadius * _innerRadius;

    coeffs[0] = e * e - four_a_sqrd * (_tubeRadius * _tubeRadius - yo * yo);
    coeffs[1] = 4.0 * f * e + 2.0 * four_a_sqrd * yo * yd;
    coeffs[2] = 2.0 * sum_d_sqrd * e + 4.0 * f * f + four_a_sqrd * yd * yd;
    coeffs[3] = 4.0 * sum_d_sqrd * f;
    coeffs[4] = sum_d_sqrd * sum_d_sqrd;

    unsigned int    rootNb = Math::solveQuartic(coeffs, roots);
    bool            intersected = false;

    for (unsigned int i = 0; i < rootNb; i++)
    {
        if (roots[i] > EPSILON)
        {
            intersected = true;
            if (roots[i] < tMin)
                tMin = roots[i];
        }
    }

    if (!intersected)
        return (false);

    h.t = tMin;
    h.localPoint = origin + r.direction * h.t;
    h.type = Hit::OUTSIDE;

    // Generate normal

    DOUBLE  param_sqrd = _innerRadius * _innerRadius + _tubeRadius * _tubeRadius;
    DOUBLE  sum_sqrd = h.localPoint.x * h.localPoint.x + h.localPoint.y * h.localPoint.y + h.localPoint.z * h.localPoint.z;
    
    h.normal = Vector3D(
        4.0 * h.localPoint.x * (sum_sqrd - param_sqrd),
        4.0 * h.localPoint.y * (sum_sqrd - param_sqrd + 2.0 * _innerRadius * _innerRadius),
        4.0 * h.localPoint.z * (sum_sqrd - param_sqrd)
    );
    
    h.normal.normalize();

    return (true);
}