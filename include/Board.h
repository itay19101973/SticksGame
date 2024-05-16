#pragma once

#include <string>
#include <list>
#include <memory>
#include "Stick.h"
#include "States.h"
#include "Utils.h"

class Board {
public:
	Board();
	void draw(sf::RenderWindow& window) const;
	bool isEmpty() const;
	void handleSticks(const sf::Vector2f& mousePos);
	int getScore() const;

private:
	std::list<std::shared_ptr<Stick>> m_sticks;
	int m_score;
	
	void updateBlockingSticks(const std::shared_ptr<Stick> stick);

	
};