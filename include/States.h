#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"

class States {
public:
	States();

	void setText(sf::Text& text);

	void draw(sf::RenderWindow& window) const;
	void update(int score);

private:
	sf::Vector2f m_position;
	sf::Clock m_clock;
	int m_levelTime;
	sf::Font m_font;

	sf::Text m_scoreText,
		m_timeText;

};