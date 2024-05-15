#include "Button.h"


//===================================================================
// ctor for button 
Button::Button(sf::Vector2f position, const sf::Texture& texture)
	: m_sprite()
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().width / 2,
		m_sprite.getLocalBounds().height / 2));
	m_sprite.setScale(BUTTON_DEFA_SIZE);


}

//===================================================================
const sf::Sprite& Button::getSprite() const
{
	return m_sprite;
}

//===================================================================
// function returns true if the button was pressed
bool Button::isClicked(sf::Vector2f mousePosition) const
{
	return this->m_sprite.getGlobalBounds().contains(mousePosition);
}

//===================================================================
void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

//===================================================================
void Button::scale(const sf::Vector2f& values)
{
	this->m_sprite.setScale(values);
}
//===================================================================
void Button::setPos(const sf::Vector2f& newPos)
{
	this->m_sprite.setPosition(newPos);
}

//===================================================================
bool Button::isFloatedOn(const sf::Vector2f& mousePosition) const
{
	return this->m_sprite.getGlobalBounds().contains(mousePosition);
}
