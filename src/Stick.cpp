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
	m_endPoint = sf::Vector2f(pos.x + length * cos(((90 + angle) * std::numbers::pi) / 180),
								pos.y + length * sin(((90+ angle) * std::numbers::pi) / 180));
	m_score = getScore(m_stick.getFillColor());
}

//=======================================================
void Stick::addBlocker(std::shared_ptr<Stick>& blocker)
{
	this->m_blocking.push_back(blocker);
}

//=======================================================
void Stick::draw(sf::RenderWindow& window)
{
	window.draw(m_stick);
	
}

//=======================================================
bool Stick::liftable() const
{
	if (this->m_blocking.size() == 0)
	{
		return true;
	}

	return false;
}

//=======================================================
bool Stick::isClicked(const sf::Vector2f& mousePos) const
{
	const auto transformedPoint = m_stick.getTransform().getInverse().transformPoint(mousePos);
	return m_stick.getLocalBounds().contains(transformedPoint);

}

//=======================================================
bool Stick::isIntersect(const std::shared_ptr<Stick>& other) const
{
	return doIntersect(this->m_stick.getPosition(), this->m_endPoint,
		other->m_stick.getPosition(), other->m_endPoint);
}

//=======================================================
void Stick::updateBlockers(std::shared_ptr<Stick> stickToRemove)
{
	for (auto it = this->m_blocking.begin(); it != this->m_blocking.end(); ++it)
	{
		if (*it == stickToRemove)
		{
			this->m_blocking.erase(it);
			break; 
		}
	}
}

int Stick::getScore() const
{
	return m_score;
}
