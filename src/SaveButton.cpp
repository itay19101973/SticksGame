#include "SaveButton.h"

void SaveButton::action(sf::RenderWindow& window)
{
}
void SaveButton::action(GameButtonFlags_t& flag)
{
	flag = Save;
}