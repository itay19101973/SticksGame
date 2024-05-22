#include "StickContainer.h"

//========================================================
// ctor for sticks container
StickContainer::StickContainer() : m_numOfSticks(0)
{
	this->m_numOfSticks = (rand() % 10) + MIN_NUM_OF_STICKS;


	//create new sticks 
	for (int i = 0; i < m_numOfSticks; i++)
	{
		auto stick = std::make_shared<Stick>();
		

		for (auto& otherStick : m_sticks)
		{
			if (otherStick->isIntersect(stick))
			{
				// add new stick to blockers of another stick
				otherStick->addBlocker(stick);
			}
		}

		//add sticks to the stick conteiner
		m_sticks.push_back(stick);	
	}

	// add sticks to the availables array
	for (const auto &stick : m_sticks)
	{
		if (stick ->liftable())
		{
			addToAvilables(stick);
		}
	}



}
//=============================================================
// ctor if game is loaded from files
StickContainer::StickContainer(int numOfSticks,
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
void StickContainer::draw(sf::RenderWindow& window) const
{
	for (const auto& stick : m_sticks)
	{
		stick->draw(window);
	}	
}

//========================================================
bool StickContainer::isEmpty() const
{
	return this->m_sticks.empty();
}

//========================================================
// this function maintaining the sticks on the board according to events 
void StickContainer::handleSticks(const sf::Vector2f& mousePos,
						int& score , sf::RenderWindow& window)
{
	// Create a list to store iterators of elements to be erased
	std::list<std::list<std::shared_ptr<Stick>>::iterator> iteratorsToErase;

	// Iterate over the list of sticks
	bool canLift = false;
	for (auto it = m_sticks.begin(); it != m_sticks.end(); ++it)
	{
		if ((*it)->isClicked(mousePos) && (*it)->liftable())
		{
			canLift= true;
			this->updateBlockingSticks(*it);
			iteratorsToErase.push_back(it); // Store iterator to be erased later
		}
	}
	// cant pick anyone to lift , draw a blocker
	if (!canLift)
	{
		for (auto it = m_sticks.rbegin(); it != m_sticks.rend(); ++it)
		{
			if ((*it)->isClicked(mousePos))
			{
				this->showBlocker(*it, window);
				break;
			}
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
int StickContainer::getRemaining() const
{
	return m_sticks.size();
}


//========================================================
int StickContainer::getLifted() const
{
	return m_numOfSticks - this->getRemaining();
}

//========================================================
int StickContainer::getOgNumOfSticks() const
{
	return this->m_numOfSticks;
}

//========================================================
int StickContainer::getLiftable() const
{
	return this->m_avilables.size();
}

//========================================================
// this functions draws all the sticks that can be lifted on the board
void StickContainer::showAvilables(sf::RenderWindow& window) const
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
			// busy wait , draws them one by one
		}

		stick->unblink();
		stick->draw(window);
		window.display();
		clock.restart();
	}
}

//========================================================
// writees the sticks data into a file this file can be loaded later
void StickContainer::writeSticksData(std::ofstream& gameFile) const
{
	for (const auto& stick : this->m_sticks)
	{
		StickData data = stick->getData();

		gameFile << data.m_pos.x << " " << data.m_pos.y << " "
			<< data.m_color << " " << data.m_angle << " " <<
			data.m_length << "\n";
	}
}


//========================================================
void StickContainer::addToAvilables(const std::shared_ptr<Stick>& stick)
{
	this->m_avilables.insert(stick);
}

//========================================================
// gets a lifted stick and removes it from the remaining sticks 
// blocker array
void StickContainer::updateBlockingSticks(const std::shared_ptr<Stick> stick)
{
	for (auto it = m_sticks.begin(); it != m_sticks.end(); ++it)
	{
		(*it)->updateBlockers(stick);
	}
}
//=============================================================
// this function draws a blocker of a stick if it was pressed but cant be lifted
void StickContainer::showBlocker(std::shared_ptr<Stick>& stick ,sf::RenderWindow& window )
{
	stick->blinkBlocker();

	sf::Clock clock;
	int deltaTime = 1;

	stick->drawTopBlocker(window);
	window.display();

	while ((int)clock.getElapsedTime().asSeconds() < deltaTime)
	{
	}

	stick->unblinkBlocker();
}
