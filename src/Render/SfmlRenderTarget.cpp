#include "Render/SfmlRenderTarget.hh"

SfmlRenderTarget::SfmlRenderTarget(unsigned int width, unsigned int height) : RenderTarget(width, height)
{
    _pixels = new sf::Uint8[_width * _height * 4];
    _texture.create(_width, _height);
    _sprite = sf::Sprite(_texture);
}

SfmlRenderTarget::~SfmlRenderTarget()
{
    delete [] _pixels;
    _pixels = nullptr;
}

void SfmlRenderTarget::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void SfmlRenderTarget::displayPixel(unsigned int x, unsigned int y, const Color &color)
{
    Color       renderColor = color;
    FLOAT       maxColor = MAX(color.r, MAX(color.g, color.b));

    if (maxColor > 1.0)
        renderColor = color / maxColor;

    _pixels[4 * (x + y * _width) + 0] = color.r * 255;
    _pixels[4 * (x + y * _width) + 1] = color.g * 255;
    _pixels[4 * (x + y * _width) + 2] = color.b * 255;
    _pixels[4 * (x + y * _width) + 3] = 255;
}

void SfmlRenderTarget::update()
{
    _texture.update(_pixels);
}
