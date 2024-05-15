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
	m_endPoint = sf::Vector2f(pos.x + length * cos(angle * std::numbers::pi / 180),
								pos.y + length * sin(angle * std::numbers::pi / 180));
	
}

void Stick::addBlocker(std::shared_ptr<Stick>& blocker)
{
	this->m_blocking.push_back(blocker);
}

void Stick::draw(sf::RenderWindow& window)
{
	window.draw(m_stick);
}

bool Stick::liftable() const
{
	return !this->m_blocking.empty();
}

bool Stick::isClicked(const sf::Vector2f& mousePos) const
{
	const auto transformedPoint = m_stick.getTransform().getInverse().transformPoint(mousePos);
	return m_stick.getLocalBounds().contains(transformedPoint);

}

bool Stick::isIntersect(const std::shared_ptr<Stick>& other) const
{
	return doIntersect(this->m_stick.getPosition(), this->m_endPoint,
		other->m_stick.getPosition(), other->m_endPoint);
}

void Stick::updateBlockers(std::shared_ptr<Stick> stickToRemove)
{
	//TODO
}