#pragma once

#include <string>
#include <list>
#include <memory>
#include "Stick.h"
#include "Utils.h"

class Board {
public:
	Board();
	Board(int numOfSticks,
		std::list<std::shared_ptr<Stick>>& sticks);
	void draw(sf::RenderWindow& window) const;
	bool isEmpty() const;
	void handleSticks(const sf::Vector2f& mousePos,
					int& score);
	int getRemaining() const;
	int getLifted() const;
	void showAvilables(sf::RenderWindow& window)const;

private:
	std::list<std::shared_ptr<Stick>> m_sticks;
	int m_numOfSticks;
	
	void addToAvilables(const std::shared_ptr<Stick>& stick);
	void updateBlockingSticks(const std::shared_ptr<Stick> stick);
	std::set<std::shared_ptr<Stick>, Stick::comperator> m_avilables;

	
};