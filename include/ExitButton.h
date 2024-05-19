#pragma once

#include "Button.h"

class ExitButton : public Button
{
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window , bool &isPressed) override;

private:

};