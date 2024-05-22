#pragma once

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "StickContainer.h"


class States {
public:
	States(const StickContainer& board, int time, int score);

	void setText(sf::Text& text);

	void draw(sf::RenderWindow& window) const;
	void update();
	int& ScoreRef();
	int getScore() const;
	int getTime() const;
	

private:
	int m_score;
	sf::Vector2f m_position;
	sf::Clock m_clock;
	int m_levelTime;
	sf::Font m_font;

	sf::Text m_scoreText,
		m_timeText,
		m_remainingText,
		m_liftableText,
		m_liftedText;

	const StickContainer& m_board;

	

};