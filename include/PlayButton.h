#pragma once

#include "Button.h"

class PlayButton : public Button
{
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window);

private:

};
