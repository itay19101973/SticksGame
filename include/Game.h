#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include "Board.h"


class Game {
public:

	Game(sf::RenderWindow& window);
	Game(sf::RenderWindow& window, const std::string& fileName);
	
	void run();
private:
	sf::RenderWindow& m_window;
	sf::Clock m_clock;
	Board m_board;
	
	
	
};