#include <cmath>

#include "Camera/PerspectiveCamera.hh"
#include "Tracer.hh"

PerspectiveCamera::PerspectiveCamera() : Camera(), _d(DEFAULT_D), _fov(DEFAULT_FOV), _zoom(1.0)
{}

PerspectiveCamera::PerspectiveCamera(const Vector3D &eye, const Vector3D &lookAt, const Vector3D &up) : Camera(eye, lookAt, up), _d(DEFAULT_D), _fov(DEFAULT_FOV), _zoom(1.0)
{}

PerspectiveCamera::~PerspectiveCamera()
{}

void PerspectiveCamera::setD(FLOAT d)
{
    _d = d;
}

FLOAT PerspectiveCamera::getD() const
{
    return (_d);
}

void PerspectiveCamera::setFov(FLOAT fov)
{
    _fov = fov;
}

FLOAT PerspectiveCamera::getFov() const
{
    return (_fov);
}

void PerspectiveCamera::setZoom(FLOAT zoom)
{
    _zoom = zoom;
}

FLOAT PerspectiveCamera::getZoom() const
{
    return (_zoom);
}

Ray PerspectiveCamera::generateRay(const Vector2D &p) const
{
    Ray r;

    r.origin = _eye;
    r.direction = _u * p.x + _v * p.y - _w * _d;

    return (r);
}

void PerspectiveCamera::renderScene(const Scene &scene, RenderTarget &target)
{
    Ray ray;
    Color color;

    unsigned int width = target.getWidth(), height = target.getHeight();

    FLOAT aspect = width / height;
    FLOAT zoomFactor = _pixelSize / _zoom;
    FLOAT angle = tan((M_PI * 0.5 * _fov) / 180.0);

    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            color = Color::black;

            for (unsigned int s = 0; s < _nbSamples; s++)
            {
                // TO-DO: Apply sample
                ray = generateRay(Vector2D(
                    zoomFactor * (x - 0.5 * width) * angle,
                    zoomFactor * (y - 0.5 * height) * angle * aspect
                ));

                color += scene.getTracer()->traceRay(ray);
            }

            target.displayPixel(x, y, color * _exposure / _nbSamples);
        }
    }
}