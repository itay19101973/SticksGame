#include "ExitButton.h"

void ExitButton::action(sf::RenderWindow& window , bool &isPressed) 
{
	isPressed = true;
	window.close();
}