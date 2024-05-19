#pragma once
#include "SFML/Graphics.hpp"
#include <set>
#include <unordered_map>
#include <string>

const unsigned int WINDOW_MANAGER_WIDTH = 869,
WINDOW_MANAGER_HEIGHT = 867,
COLOR_NUMBER = 6,
STICK_WIDTH = 10,
OFFSET = 200,
STATE_OFFSET = 180,
MIN_NUM_OF_STICKS = 20,
DEFAULT_TIME = 40,
GAME_MENU_START_X = 25,
GAME_BUTTON_OFFSETS = 60,
GAME_MENU_START_Y = 100,
DEFA_SCORE = 0;


const sf::Vector2f MENU_BUTTON_DEFA_SIZE = { 0.33f, 0.33f },
BUTTON_FLOATED_SIZE = { 0.4f, 0.4f },
GAME_MENU_BUTTON_SIZE = { 0.1f , 0.1f },
PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
					WINDOW_MANAGER_HEIGHT / 2 - 200 },
	LOAD_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
					WINDOW_MANAGER_HEIGHT / 2},
	EXIT_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - MENU_BUTTON_DEFA_SIZE.x / 2,
						WINDOW_MANAGER_HEIGHT / 2 + 200 },
	HINT_BUTTON_POS = {  GAME_MENU_START_X , GAME_MENU_START_Y },
	SAVE_BUTTON_POS = { GAME_MENU_START_X , GAME_MENU_START_Y + GAME_BUTTON_OFFSETS };
	;


const std::vector<sf::Color> COLOR_SET = { sf::Color::Blue ,
								sf::Color::Green ,
								sf::Color::Yellow ,
								sf::Color::Red ,
								sf::Color::Magenta ,
								sf::Color::White };

enum GameButtonFlags_t{None , Hint , Save };


struct StickData {
	sf::Vector2f m_pos;
	int m_color,
		m_angle,
		m_length;
	
};