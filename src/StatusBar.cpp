#include "StatusBar.h"

StatusBar::StatusBar(const StickContainer& board, int time, int score)
	: m_levelTime(time), m_score(score),
	m_position(sf::Vector2f(0, 0)), m_clock(),
	m_board(board)
{

	sf::Vector2f PosStates = { 20   , 20 };

	m_font.loadFromFile("StatesFont.ttf");

	// setting the wanted texts
	this->setText(m_scoreText);
	this->setText(m_timeText);
	this->setText(m_liftableText);
	this->setText(m_liftedText);
	this->setText(m_remainingText);

	//  level time text , clock and keys
	this->m_scoreText.setPosition(PosStates);
	PosStates.x += STATE_OFFSET;
	this->m_timeText.setPosition(PosStates);
	PosStates.x += STATE_OFFSET;
	this->m_liftableText.setPosition(PosStates);
	PosStates.x += STATE_OFFSET;
	this->m_liftedText.setPosition(PosStates);
	PosStates.x += STATE_OFFSET;
	this->m_remainingText.setPosition(PosStates);
	PosStates.x += STATE_OFFSET;
	
}


//======================================================
void StatusBar::setText(sf::Text& text)
{
	text.setFont(m_font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Yellow);
}

//======================================================
void StatusBar::draw(sf::RenderWindow& window) const
{
	window.draw(m_timeText);
	window.draw(m_scoreText);
	window.draw(m_liftedText);
	window.draw(m_remainingText);
	window.draw(m_liftableText);


}


//======================================================
void StatusBar::update()
{

	this->m_timeText.setString("Time\n" + std::to_string(m_levelTime - 
		(int)m_clock.getElapsedTime().asSeconds()));

	this->m_scoreText.setString("Score\n" 
		+ std::to_string(m_score));

	this->m_remainingText.setString("Remain\n" 
		+ std::to_string(m_board.getRemaining()));

	this->m_liftedText.setString("Lifted\n" 
		+ std::to_string(m_board.getLifted()));

	this->m_liftableText.setString("Liftable\n" + 
		std::to_string(m_board.getLiftable()));

	

}

//======================================================
int& StatusBar::ScoreRef()
{
	return m_score;
}

//======================================================
int StatusBar::getScore() const
{
	return m_score;
}

//======================================================
int StatusBar::getTime() const
{
	return this->m_levelTime - (int)m_clock.getElapsedTime().asSeconds();
}

void StatusBar::addTime(const int& time)
{
	this->m_levelTime += time;
}
