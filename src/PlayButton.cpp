#include "PlayButton.h"

void PlayButton::action(sf::RenderWindow& window , bool &isPressed)
{
	Game game(window);
	game.run();


}