#pragma once
#include "Button.h"

class SaveButton : public Button {
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window) override;
	virtual void action(GameButtonFlags_t& flag)override;
private:

};