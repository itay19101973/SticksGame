#include "Stick.h"

//=============================================================
// ctor for sticks , use this if a new game starts
Stick::Stick()
{

	this->getRandomVals();

	this->setData(m_data);
}

//=======================================================
// genarates random values do a stick (position , color , length)
void Stick::getRandomVals()
{
	m_data.m_pos = sf::Vector2f(OFFSET + rand() % (WINDOW_MANAGER_WIDTH - 2 * OFFSET),
		OFFSET + rand() % (WINDOW_MANAGER_HEIGHT - 2 * OFFSET));
	m_data.m_angle = rand() % 180;
	m_data.m_color = rand() % COLOR_NUMBER;
	m_data.m_length = (rand() % 100) + 300;
}


//=======================================================
// ctor for sticks , use if the data is being given from a file
Stick::Stick(const StickData& data) : m_data(data)
{

	this->setData(data);
}
//=============================================================
//this function sets the values to a stick according to a specific data given
// use when loading saved game
void Stick::setData(const StickData& data)
{
	m_stick.setPosition(sf::Vector2f(data.m_pos.x, data.m_pos.y));
	m_stick.setFillColor(COLOR_SET[data.m_color]);
	m_stick.setRotation(data.m_angle);
	m_stick.setSize(sf::Vector2f(STICK_WIDTH, data.m_length));
	m_endPoint = sf::Vector2f(data.m_pos.x + data.m_length *
		cos(((90 + data.m_angle) * std::numbers::pi) / 180),
		data.m_pos.y + data.m_length *
		sin(((90 + data.m_angle) * std::numbers::pi) / 180));
	m_stick.setOutlineThickness(1);
	m_stick.setOutlineColor(sf::Color::White);
	m_score = getStickScore(m_stick.getFillColor());
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
	return m_blocking.empty();
}

//=======================================================
bool Stick::isClicked(const sf::Vector2f& mousePos) const
{
	const auto transformedPoint = m_stick.getTransform().getInverse().transformPoint(mousePos);
	return m_stick.getLocalBounds().contains(transformedPoint);

}

//=======================================================
// checks if 2 sticks intersects
bool Stick::isIntersect(const std::shared_ptr<Stick>& other) const
{
	return doIntersect(this->m_stick.getPosition(), this->m_endPoint,
		other->m_stick.getPosition(), other->m_endPoint);
}

//=======================================================
// gets a stick to remove and removes it from the sticks that he blocks
// it removes it from every sticks array blocker
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
//=============================================================

int Stick::getScore() const
{
	return m_score;
}
//=============================================================
void Stick::blink()
{
	m_stick.setOutlineColor(sf::Color::White);
	m_stick.setOutlineThickness(5);
}
//=============================================================
void Stick::unblink()
{
	m_stick.setOutlineColor(sf::Color::White);
	m_stick.setOutlineThickness(1);
}
//=============================================================
const StickData& Stick::getData() const
{
	return this->m_data;
}
//=============================================================
void Stick::blinkBlocker()
{
	m_blocking[0]->blink();
}
//=============================================================
void Stick::unblinkBlocker()
{
	m_blocking[0]->unblink();
}
//=============================================================
// function draws the top blocker of a stick
void Stick::drawTopBlocker(sf::RenderWindow & window) const
{
	m_blocking[0]->draw(window);
}
/*=============================================================
*                 operator overloading 
=============================================================*/
bool operator==(const Stick& stick1, const Stick& stick2)
{
	return stick1.getScore() == stick2.getScore();
}
//=============================================================
bool operator<(const Stick& stick1, const Stick& stick2)
{
	return stick1.getScore() < stick2.getScore();
}
//=============================================================
bool operator<=(const Stick& stick1, const Stick& stick2)
{
	return (stick1 < stick2) || (stick1 == stick2);
}
//=============================================================
bool operator>(const Stick& stick1, const Stick& stick2)
{
	return !(stick1 <= stick2);
}
//=============================================================
bool operator>=(const Stick& stick1, const Stick& stick2)
{
	return (stick1 > stick2) || (stick1 == stick2);
}
//=============================================================
bool Stick::comperator::operator()(const std::shared_ptr<Stick>& stick1, 
	const std::shared_ptr<Stick>& stick2) const
{
	return (*stick1) > (*stick2);
}
