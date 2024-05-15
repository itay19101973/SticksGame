#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"

class Controller
{
public:
	Controller();
	~Controller();


	void run();
private:
	Menu m_menu;
};
