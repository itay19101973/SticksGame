#include "HintButton.h"

void HintButton::action(sf::RenderWindow& window)
{
}

void HintButton::action(GameButtonFlags_t& flag)
{
	flag = Hint;
}
