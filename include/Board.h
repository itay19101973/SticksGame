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

private:
	std::list<std::shared_ptr<Stick>> m_sticks;
	//States m_states; TODO
	
	void updateBlockingSticks(const std::shared_ptr<Stick> stick);

	
};