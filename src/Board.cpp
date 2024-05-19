#include "Board.h"

//========================================================
Board::Board() : m_numOfSticks(0)
{
	this->m_numOfSticks = (rand() % 10) + MIN_NUM_OF_STICKS;

	for (int i = 0; i < m_numOfSticks; i++)
	{
		auto stick = std::make_shared<Stick>();
		

		for (auto& otherStick : m_sticks)
		{
			if (otherStick->isIntersect(stick))
			{
				otherStick->addBlocker(stick);
			}
		}


		m_sticks.push_back(stick);	
	}

	for (const auto &stick : m_sticks)
	{
		if (stick ->liftable())
		{
			addToAvilables(stick);
		}
	}



}

Board::Board(int numOfSticks,
	std::list<std::shared_ptr<Stick>>& sticks)
	: m_numOfSticks(numOfSticks), m_sticks(sticks)
{
	for (const auto& stick : m_sticks)
	{
		if (stick->liftable())
		{
			addToAvilables(stick);
		}
	}
}

//========================================================
void Board::draw(sf::RenderWindow& window) const
{
	for (const auto& stick : m_sticks)
	{
		stick->draw(window);
	}	
}

//========================================================
bool Board::isEmpty() const
{
	return this->m_sticks.empty();
}

//========================================================
void Board::handleSticks(const sf::Vector2f& mousePos,
						int& score)
{
	// Create a list to store iterators of elements to be erased
	std::list<std::list<std::shared_ptr<Stick>>::iterator> iteratorsToErase;

	// Iterate over the list of sticks
	for (auto it = m_sticks.begin(); it != m_sticks.end(); ++it)
	{
		if ((*it)->isClicked(mousePos) && (*it)->liftable())
		{
			this->updateBlockingSticks(*it);
			iteratorsToErase.push_back(it); // Store iterator to be erased later
		}
	}

	// Erase elements using stored iterators
	for (auto& it : iteratorsToErase)
	{
		score += (*it)->getScore();
		m_sticks.erase(it);

	
	}

}

//========================================================
int Board::getRemaining() const
{
	return m_sticks.size();
}


//========================================================
int Board::getLifted() const
{
	return m_numOfSticks - this->getRemaining();
}

void Board::showAvilables(sf::RenderWindow& window) const
{
	sf::Clock clock;

	int deltaTime = 1;

	for (auto &stick : m_avilables)
	{
		stick->blink();
		stick->draw(window);
		window.display();

		while ((int)clock.getElapsedTime().asSeconds() < deltaTime)
		{
		}

		stick->unblink();
		stick->draw(window);
		clock.restart();
	}
}




void Board::addToAvilables(const std::shared_ptr<Stick>& stick)
{
	this->m_avilables.insert(stick);
}

//========================================================
void Board::updateBlockingSticks(const std::shared_ptr<Stick> stick)
{
	for (auto it = m_sticks.begin(); it != m_sticks.end(); ++it)
	{
		(*it)->updateBlockers(stick);
	}
}
