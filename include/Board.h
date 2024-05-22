#pragma once

#include <string>
#include <list>
#include <memory>
#include "Stick.h"
#include "Utils.h"
#include <fstream>



class Board {
public:
	Board();
	Board(int numOfSticks,
		std::list<std::shared_ptr<Stick>>& sticks);
	void draw(sf::RenderWindow& window) const;
	bool isEmpty() const;
	void handleSticks(const sf::Vector2f& mousePos,
					int& score , sf::RenderWindow& window);
	int getRemaining() const;
	int getLifted() const;
	int getOgNumOfSticks() const;
	int getLiftable() const;

	void showAvilables(sf::RenderWindow& window)const;
	void writeSticksData(std::ofstream& gameFile) const;

private:
	std::list<std::shared_ptr<Stick>> m_sticks;
	int m_numOfSticks;
	
	void addToAvilables(const std::shared_ptr<Stick>& stick);
	void updateBlockingSticks(const std::shared_ptr<Stick> stick);
	void showBlocker( std::shared_ptr<Stick>& stick , sf::RenderWindow& window);
	std::multiset<std::shared_ptr<Stick>, Stick::comperator> m_avilables;

	
};