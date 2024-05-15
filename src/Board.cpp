#include "Board.h"

Board::Board()
{
	int numOfSticks = (rand() % 10) + MIN_NUM_OF_STICKS;

	for (int i = 0; i < numOfSticks; i++)
	{
		m_sticks.push_back(std::make_shared<Stick>());
	}
}

void Board::draw(sf::RenderWindow& window)
{
	for (const auto& stick : m_sticks)
	{
		stick->draw(window);
	}
}
