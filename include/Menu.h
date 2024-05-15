#pragma once

#include <vector>
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Menu
{
public:
	Menu();
	~Menu() = default;

private:
	std::vector<std::unique_ptr<Button>> m_buttons;
};
