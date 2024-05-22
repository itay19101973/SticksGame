#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include "StickContainer.h"
#include "Menu.h"
#include "memory"
#include "HintButton.h"
#include "SaveButton.h"
#include "Settings.h"
#include "States.h"
#include <fstream>




class Game {
public:

	Game(sf::RenderWindow& window);
	Game(sf::RenderWindow& window, 
		StickContainer& m_board,
		int time,
		int score);
	void run();
	void addButtonsToGameMenu();
	void handleButtonEvents(GameButtonFlags_t& event);

private:
	Menu m_menu;
	sf::RenderWindow& m_window;
	sf::Clock m_clock;
	StickContainer m_stickContainer;
	States m_states;
	
	void saveGame() const;
	void showEndScreen(bool win) const;
	
	void checkWin(bool& win);
};