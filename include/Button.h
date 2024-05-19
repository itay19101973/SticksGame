#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "ImageManager.h"

class Button
{
public:
	Button(sf::Vector2f position, const sf::Texture& texture , sf::Vector2f scale);
	virtual ~Button() = default;

	const sf::Sprite& getSprite() const;
	void scale(const sf::Vector2f& values);
	void setPos(const sf::Vector2f& newPos);
	bool isClicked(sf::Vector2f mousePosition) const;
	void draw(sf::RenderWindow& window) const;
	bool isFloatedOn(const sf::Vector2f& mousePosition) const;
	virtual void action(sf::RenderWindow& window ) = 0;
	virtual void action(GameButtonFlags_t& flag) = 0;
	sf::Vector2f getFloatedSize();
	sf::Vector2f getDefSize();


private:
	sf::Sprite m_sprite;
	sf::Vector2f m_defSize, m_floatedSize;
};
