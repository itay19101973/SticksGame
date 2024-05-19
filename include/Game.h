#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include "Board.h"
#include "Menu.h"
#include "memory"
#include "HintButton.h"
#include "SaveButton.h"
#include "Settings.h"
#include "States.h"




class Game {
public:

	Game(sf::RenderWindow& window);
	Game(sf::RenderWindow& window, 
		Board& m_board,
		int time,
		int score);
	void run();
	void addButtonsToGameMenu();
	void handleButtonEvents(GameButtonFlags_t& event);
private:
	Menu m_menu;
	sf::RenderWindow& m_window;
	sf::Clock m_clock;
	Board m_board;

	States m_states;
	
	
};