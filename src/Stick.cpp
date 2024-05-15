#include "Stick.h"

Stick::Stick()
{
	sf::Vector2f pos =sf::Vector2f ( OFFSET + rand() % (WINDOW_MANAGER_WIDTH - 2 * OFFSET) ,
				OFFSET + rand() % (WINDOW_MANAGER_HEIGHT - 2 * OFFSET) );
	int angle = rand() % 180,
		color = rand() % COLOR_NUMBER,
		length = (rand() % 100) + 300;

	m_stick.setPosition(pos);
	m_stick.setFillColor(COLOR_SET[color]);
	m_stick.setRotation(angle);
	m_stick.setSize(sf::Vector2f( STICK_WIDTH , length ));
	m_stick.setOrigin(sf::Vector2f(pos.x + ))
}

void Stick::draw(sf::RenderWindow& window)
{
	window.draw(m_stick);
}
