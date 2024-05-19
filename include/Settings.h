#pragma once
#include "SFML/Graphics.hpp"
#include <set>
#include <unordered_map>

const unsigned int WINDOW_MANAGER_WIDTH = 869,
WINDOW_MANAGER_HEIGHT = 867,
COLOR_NUMBER = 6,
STICK_WIDTH = 10,
OFFSET = 200,
STATE_OFFSET = 180,
MIN_NUM_OF_STICKS = 20,
DEFAULT_TIME = 40;

const sf::Vector2f BUTTON_DEFA_SIZE = { 0.33f, 0.33f },
					BUTTON_FLOATED_SIZE = { 0.4f, 0.4f },
					PLAY_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
										WINDOW_MANAGER_HEIGHT / 2 - 200 },
					EXIT_BTN_POS = { WINDOW_MANAGER_WIDTH / 2 - BUTTON_DEFA_SIZE.x / 2,
										WINDOW_MANAGER_HEIGHT / 2 + 200 };


const std::vector<sf::Color> COLOR_SET = { sf::Color::Blue ,
								sf::Color::Green ,
								sf::Color::Yellow ,
								sf::Color::Red ,
								sf::Color::Magenta ,
								sf::Color::White };


