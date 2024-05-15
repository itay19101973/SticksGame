#pragma once

#include <SFML/Graphics.hpp>

class Controller
{
public:
	Controller();
	~Controller();


	void run();
private:
	Menu m_menu;
};
