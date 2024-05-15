#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Stick
{
public:
	Stick();
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_stick;
};