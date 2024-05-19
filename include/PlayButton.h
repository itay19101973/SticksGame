#pragma once
#include "Game.h"
#include "Button.h"


class PlayButton : public Button
{
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window )override;
	virtual void action(GameButtonFlags_t& flag)override;


private:

};
