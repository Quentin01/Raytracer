#pragma once

#include <SFML/Graphics.hpp>
#include "Render/RenderTarget.hh"

class SfmlRenderTarget : public RenderTarget, public sf::Drawable
{
public:
	SfmlRenderTarget(unsigned int width, unsigned int height);
	virtual ~SfmlRenderTarget();

	virtual void	update();

	virtual void	draw(sf::RenderTarget &target, sf::RenderStates states) const;
	virtual void	displayPixel(unsigned int x, unsigned int y, const Color &color);

protected:
	sf::Uint8	*_pixels;
	sf::Texture	_texture;
	sf::Sprite	_sprite;
};