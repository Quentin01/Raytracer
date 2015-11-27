#include "Render/RenderTarget.hh"

RenderTarget::RenderTarget(unsigned int width, unsigned int height) : _width(width), _height(height)
{}

RenderTarget::~RenderTarget()
{}

void RenderTarget::update()
{}

unsigned int RenderTarget::getWidth() const
{
    return (_width);
}

unsigned int RenderTarget::getHeight() const
{
    return (_height);
}