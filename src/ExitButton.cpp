#include "ExitButton.h"

void ExitButton::action(sf::RenderWindow& window )
{
	window.close();
}

void ExitButton::action(GameButtonFlags_t& flag)
{
}
