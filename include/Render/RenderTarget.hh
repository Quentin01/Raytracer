#pragma once

#include "Utils/Color.hh"

class RenderTarget
{
public:
    RenderTarget(unsigned int width, unsigned int height);
    RenderTarget(const RenderTarget&) = delete;
    RenderTarget(const RenderTarget&&) = delete;

    virtual ~RenderTarget();

    RenderTarget    &operator=(const RenderTarget&) = delete;

    unsigned int    getWidth() const;
    unsigned int    getHeight() const;

    virtual void    update();
    virtual void    displayPixel(unsigned int x, unsigned int y, const Color &color) = 0;

protected:
    unsigned int    _width;
    unsigned int    _height;
};