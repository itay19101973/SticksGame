#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "ImageManager.h"

class Button
{
public:
	Button(sf::Vector2f position, const sf::Texture& texture);
	virtual ~Button() = default;

	const sf::Sprite& getSprite() const;
	void scale(const sf::Vector2f& values);
	void setPos(const sf::Vector2f& newPos);
	bool isClicked(sf::Vector2f mousePosition) const;
	void draw(sf::RenderWindow* window) const;
	virtual void action(sf::RenderWindow* window,
		const ImageManager& textures) = 0;


private:
	sf::Sprite m_sprite;
};
