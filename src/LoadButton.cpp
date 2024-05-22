#include "LoadButton.h"

void LoadButton::action(sf::RenderWindow& window)
{
	std::string filenName = openFileDialog();
	std::ifstream gameFile(filenName);
	if (!gameFile.is_open())
	{
		throw FileException("Failed to open the file.");
	}

	std::list<std::shared_ptr<Stick>> sticks;
	int numOfSticks,
		time,
		score;
	

	// GetStickData and create a vector of sticks
	gameFile >> numOfSticks >> time >> score;

	if (gameFile.fail())
	{
		gameFile.clear();
		throw WrongInputException("Invalid file format , failed to read data");
	}

	if (time > MAX_TIME || time <= 0) {
		throw TimeException("Time is out of range");
	}
	
	this->createStickContainer(gameFile, sticks);

	gameFile.close();
	// Create a container from sticks
	StickContainer container(numOfSticks, sticks);

	
	// Create a game from states and container
	auto game = Game(window, container, time, score);

	game.run();

}

void LoadButton::createStickContainer(std::ifstream& gameFile, 
	std::list<std::shared_ptr<Stick>>& sticks)
{

	std::string line;
	std::getline(gameFile, line);

	while (std::getline(gameFile, line))
	{
		auto stick = this->readStickData(line);

		for (auto& otherStick : sticks)
		{
			if (otherStick->isIntersect(stick))
			{
				otherStick->addBlocker(stick);
			}
		}

		sticks.push_back(stick);
	}
}

std::shared_ptr<Stick> LoadButton::readStickData(std::string& line)
{
	StickData data;

	std::istringstream iss(line);

	iss >> data.m_pos.x >> data.m_pos.y >> data.m_color >> data.m_angle >> data.m_length;

	auto stick = std::make_unique<Stick>(data);

	return stick;
}

void LoadButton::action(GameButtonFlags_t& flag)
{
}
