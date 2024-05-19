#include "LoadButton.h"

void LoadButton::action(sf::RenderWindow& window)
{
	auto game = Game(window, "Board.txt");
	game.run();
}

void LoadButton::action(GameButtonFlags_t& flag)
{
}
