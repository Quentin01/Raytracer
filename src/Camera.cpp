#include "Camera.hh"

Camera::Camera() : Camera(Vector3D(0.0), Vector3D(0.0), Vector3D(0.0))
{}

Camera::Camera(const Vector3D &eye, const Vector3D &lookAt, const Vector3D &up) : _nbSamples(1), _pixelSize(1.0), _exposure(1.0), _eye(eye), _lookAt(lookAt), _up(up)
{}

Camera::~Camera()
{}

void Camera::computeFrame()
{
	_w = _eye - _lookAt;
	_w.normalize();
	_u = _up.cross(_w);
	_u.normalize();
	_v = _w.cross(_u);
}

void Camera::setNbSamples(unsigned int nbSamples)
{
	if (nbSamples > 0)
		_nbSamples = nbSamples;
	else
		_nbSamples = 1;
}

unsigned int Camera::getNbSamples() const
{
	return (_nbSamples);
}

void Camera::setPixelSize(FLOAT pixelSize)
{
	if (pixelSize > 0.0)
		_pixelSize = pixelSize;
	else
		_pixelSize = 1.0;
}

FLOAT Camera::getPixelSize() const
{
	return (_pixelSize);
}

void Camera::setExposure(FLOAT exposure)
{
	if (exposure > 0.0)
		_exposure = exposure;
	else
		_exposure = 0.0;
}

FLOAT Camera::getExposure() const
{
	return (_exposure);
}

void Camera::setEye(const Vector3D &eye)
{
	_eye = eye;
}

void Camera::setEye(DOUBLE x, DOUBLE y, DOUBLE z)
{
	_eye.x = x;
	_eye.y = y;
	_eye.z = z;
}

const Vector3D &Camera::getEye() const
{
	return (_eye);
}

void Camera::setLookAt(const Vector3D &lookAt)
{
	_lookAt = lookAt;
}

void Camera::setLookAt(DOUBLE x, DOUBLE y, DOUBLE z)
{
	_lookAt.x = x;
	_lookAt.y = y;
	_lookAt.z = z;
}

const Vector3D &Camera::getLookAt() const
{
	return (_lookAt);
}

void Camera::setUp(const Vector3D &up)
{
	_up = up;
}

void Camera::setUp(DOUBLE x, DOUBLE y, DOUBLE z)
{
	_up.x = x;
	_up.y = y;
	_up.z = z;
}

const Vector3D &Camera::getUp() const
{
	return (_up);
}