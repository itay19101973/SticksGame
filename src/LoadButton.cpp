#include "LoadButton.h"

void LoadButton::action(sf::RenderWindow& window)
{
	std::ifstream gameFile("../resources/Board.txt");
	std::list<std::shared_ptr<Stick>> sticks;
	int numOfSticks,
		time,
		score;
	

	// GetStickData and create a vector of sticks
	gameFile >> numOfSticks >> time >> score;
	
	this->createStickContainer(gameFile, sticks);

	gameFile.close();
	// Create a board from sticks //TODO
	Board board(numOfSticks, sticks);

	
	// Create a game from states and board
	auto game = Game(window, board, time, score);

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
