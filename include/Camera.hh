#pragma once

#include "Render/RenderTarget.hh"
#include "Scene.hh"
#include "Utils/Vector3D.hh"

class Camera
{
public:
    Camera();
    Camera(const Vector3D &eye, const Vector3D &lookAt, const Vector3D &up);

    Camera(const Camera&) = delete;
    Camera(const Camera&&) = delete;

    virtual ~Camera();

    Camera&         operator=(const Camera&) = delete;

    void            setNbSamples(unsigned int nbSamples);
    unsigned int    getNbSamples() const;

    void            setPixelSize(FLOAT pixelSize);
    FLOAT           getPixelSize() const;

    void            setExposure(FLOAT exposure);
    FLOAT           getExposure() const;

    void            setEye(const Vector3D &eye);
    void            setEye(DOUBLE x, DOUBLE y, DOUBLE z);
    const Vector3D  &getEye() const;

    void            setLookAt(const Vector3D &lookAt);
    void            setLookAt(DOUBLE x, DOUBLE y, DOUBLE z);
    const Vector3D  &getLookAt() const;

    void            setUp(const Vector3D &up);
    void            setUp(DOUBLE x, DOUBLE y, DOUBLE z);
    const Vector3D  &getUp() const;

    virtual void    computeFrame();
    virtual void    renderScene(const Scene& scene, RenderTarget &target) = 0;

protected:
    unsigned int    _nbSamples;
    FLOAT           _pixelSize;
    FLOAT           _exposure;

    Vector3D        _eye;
    Vector3D        _lookAt;
    Vector3D        _up;

    Vector3D        _u, _v, _w;
};