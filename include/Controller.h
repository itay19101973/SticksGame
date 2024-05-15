#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Settings.h"

class Controller
{
public:
	Controller();
	~Controller() = default;


	void run();
private:
	Menu m_menu;
};
