#include "PlayButton.h"

void PlayButton::action(sf::RenderWindow& window)
{
	Game game(window);
	game.run();
}

void PlayButton::action(GameButtonFlags_t& flag)
{
}
