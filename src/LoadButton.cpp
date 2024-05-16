#include "LoadButton.h"

void LoadButton::action(sf::RenderWindow& window, bool &isPressed)
{
	auto game = Game(window, "Board.txt");

	game.run();
}