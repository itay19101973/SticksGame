#pragma once

#include "Button.h"
#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include "FileException.h"
#include "WrongInputException.h"
#include "TimeException.h"



class LoadButton : public Button
{
public:
	using Button::Button;
	virtual void action(sf::RenderWindow& window ) override;
	virtual void action(GameButtonFlags_t& flag) override;

private:
	void createStickContainer(std::ifstream& gameFile,
		std::list<std::shared_ptr<Stick>>& sticks);
	std::shared_ptr<Stick> readStickData(std::string& line);

};
