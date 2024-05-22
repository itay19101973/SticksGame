#pragma once
#include "Button.h"

/**
 * Represents a button for saving the game state.
 */

class SaveButton : public Button {
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window) override;
	virtual void action(GameButtonFlags_t& flag)override;
private:

};