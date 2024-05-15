#include "Game.h"

//========================================
Game::Game(sf::RenderWindow& window)
	: m_window(window), m_board()
{
}

//=========================================
// Ctor from file
Game::Game(sf::RenderWindow& window, const std::string& fileName)
	: m_window(window)
{
	auto file(fileName); //TODO
}


void Game::run()
{
	
}