#pragma once

#include "Camera.hh"
#include "Utils/Vector2D.hh"

class PerspectiveCamera : public Camera
{
public:
    PerspectiveCamera();
    PerspectiveCamera(const Vector3D &eye, const Vector3D &lookAt, const Vector3D &up);
    virtual ~PerspectiveCamera();

    void            setD(FLOAT d);
    FLOAT           getD() const;
    void            setZoom(FLOAT zoom);
    FLOAT           getZoom() const;

    virtual Ray     generateRay(const Vector2D &p) const;
    virtual void    renderScene(const Scene& scene, RenderTarget &target);

protected:
    FLOAT           _d;
    FLOAT           _zoom;
};