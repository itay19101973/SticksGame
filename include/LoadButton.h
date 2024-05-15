#pragma once

#include "Button.h"
#include "Game.h"

class LoadButton : public Button
{
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window);

private:

};
