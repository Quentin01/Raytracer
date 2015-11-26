#include "Camera/PerspectiveCamera.hh"
#include "Tracer.hh"

PerspectiveCamera::PerspectiveCamera() : Camera(), _d(500.0), _zoom(1.0)
{}

PerspectiveCamera::PerspectiveCamera(const Vector3D &eye, const Vector3D &lookAt, const Vector3D &up) : Camera(eye, lookAt, up), _d(500.0), _zoom(1.0)
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

void PerspectiveCamera::setZoom(FLOAT zoom)
{
	_zoom = zoom;
}

FLOAT PerspectiveCamera::getZoom() const
{
	return (_zoom);
}

Ray	PerspectiveCamera::generateRay(const Vector2D &p) const
{
	Ray r;

	r.origin = _eye;
	r.direction = _u * p.x + _v * p.y - _w * _d;

	return (r);
}

void PerspectiveCamera::renderScene(const Scene &scene, RenderTarget &target)
{
	Ray	ray;
	Color color;
	unsigned int width = target.getWidth(), height = target.getHeight();
	FLOAT zoomFactor = _pixelSize / _zoom;

	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			color = Color::black;

			for (unsigned int s = 0; s < _nbSamples; s++)
			{
				// TO-DO: Apply sample
				ray = generateRay(Vector2D(
					zoomFactor * (x - 0.5 * width),
					zoomFactor * (y - 0.5 * height)
				));

				color += scene.getTracer()->traceRay(ray);
			}

			target.displayPixel(x, y, color * _exposure / _nbSamples);
		}
	}
}