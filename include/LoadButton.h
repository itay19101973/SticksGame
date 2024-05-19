#pragma once

#include "Button.h"
#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include <memory>


class LoadButton : public Button
{
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window , bool &isPressed);

private:
	void createStickContainer(std::ifstream& gameFile,
		std::list<std::shared_ptr<Stick>>& sticks);
	std::shared_ptr<Stick> readStickData(std::string& line);

};
