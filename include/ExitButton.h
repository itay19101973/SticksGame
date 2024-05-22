#pragma once

#include "Button.h"

/**
 * Represents an exit button in the game.
 */


class ExitButton : public Button
{
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window) override;
	virtual void action(GameButtonFlags_t& flag) override;
private:

};