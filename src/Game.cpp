#include "Game.h"


//========================================
Game::Game(sf::RenderWindow& window)
	: m_window(window), m_board(), m_states()
{
}

//=========================================
// Ctor from file
Game::Game(sf::RenderWindow& window, const std::string& fileName)
	: m_window(window) 
{
	auto file(fileName); //TODO
}


void Game::addGameMenuButtons()
{
	//TODO
}

//==============================================
void Game::run()
{
	sf::Vector2f mousePos;
	m_window.setFramerateLimit(60);

	this->addButtonsToGameMenu();




	while (m_window.isOpen() && !m_board.isEmpty())
	{
		m_window.clear();

		m_board.draw(m_window);
		m_states.draw(m_window);
		m_menu.draw(m_window);

		m_window.display();

		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				m_window.close();
				break;

			case sf::Event::MouseButtonReleased:

				mousePos = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				// handle buttons TODO

				this->m_board.handleSticks(mousePos);
				

			}
		}

		this->m_states.update(m_board.getScore());
	}
}

void Game::addButtonsToGameMenu()
{
	//TODO - CHANGE FOR THE REAL PICTURES
	ImageManager& manager = ImageManager::getInstance();

	this->m_menu.addButton(std::make_unique<HintButton>(HINT_BUTTON_POS,
		manager.getImage("PlayButton")  , GAME_MENU_BUTTON_SIZE) , "HintButton");
	this->m_menu.addButton(std::make_unique<SaveButton>(SAVE_BUTTON_POS, 
		manager.getImage("PlayButton") , GAME_MENU_BUTTON_SIZE ), "SaveButton");
}

