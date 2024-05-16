#include "States.h"

States::States()
	: m_levelTime(DEFAULT_TIME), m_position(sf::Vector2f(0, 0)), m_clock()
{

	sf::Vector2f PosStates = { 20   , 20 };

	m_font.loadFromFile("StatesFont.ttf");

	// setting the wanted texts
	this->setText(m_scoreText);
	this->setText(m_timeText);

	//  level time text , clock and keys
	this->m_scoreText.setPosition(PosStates);
	PosStates.x += STATE_OFFSET;
	this->m_timeText.setPosition(PosStates);
	PosStates.x += STATE_OFFSET;
	
}


//======================================================
void States::setText(sf::Text& text)
{
	text.setFont(m_font);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::Yellow);
}

//======================================================
void States::draw(sf::RenderWindow& window) const
{
	window.draw(m_timeText);
	window.draw(m_scoreText);


}


//======================================================
void States::update(int score)
{

	m_timeText.setString("Time: " + std::to_string((int)m_clock.getElapsedTime().asSeconds()));

	m_scoreText.setString("Score: " + std::to_string(score));

}
