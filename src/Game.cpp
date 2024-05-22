#include "Game.h"


//========================================
Game::Game(sf::RenderWindow& window)
	: m_window(window), m_stickContainer(), m_states(m_stickContainer, DEFAULT_TIME, DEFA_SCORE)
{
}

//=========================================
// Ctor from file
Game::Game(sf::RenderWindow& window, StickContainer& container,
	int time,
	int score)
	: m_window(window), m_stickContainer(container), m_states(m_stickContainer, time, score)
{
	
}


//==============================================
// main game loop
void Game::run()
{
	sf::Vector2f mousePos;
	m_window.setFramerateLimit(60);

	this->addButtonsToGameMenu();

	GameButtonFlags_t buttonEvent = None;
	bool win = false;

	sf::Sprite background;

	this->loadBackground(background);



	// main game loop
	while (m_window.isOpen() && m_states.getTime() > 0 && !win)
	{
		m_window.clear();

		m_window.draw(background);
		m_stickContainer.draw(m_window);
		m_states.draw(m_window);
		m_menu.draw(m_window);

		m_window.display();

		// event handling
		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				m_window.close();
				break;

			case sf::Event::MouseButtonReleased:

				mousePos = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				m_menu.handleClicks(mousePos, m_window , buttonEvent);

				this->m_stickContainer.handleSticks(mousePos, this->m_states.ScoreRef() , m_window);
			case sf::Event::MouseMoved:

				sf::Event::MouseMoveEvent mouse = event.mouseMove;
				mousePos = m_window.mapPixelToCoords({ mouse.x, mouse.y });
				m_menu.handleFloating(mousePos);
			
			}
		}

		this->m_states.update();
		this->handleButtonEvents(buttonEvent);
		this->checkWin(win);
	}

	this->showEndScreen(win);
}
//=============================================================
void Game::addButtonsToGameMenu()
{
	ImageManager& manager = ImageManager::getInstance();

	this->m_menu.addButton(std::make_unique<HintButton>(HINT_BUTTON_POS,
		manager.getImage("HintButton")  , GAME_MENU_BUTTON_SIZE) , "HintButton");
	this->m_menu.addButton(std::make_unique<SaveButton>(SAVE_BUTTON_POS, 
		manager.getImage("SaveButton") , GAME_MENU_BUTTON_SIZE ), "SaveButton");
}
//=============================================================
// this function handles the button events according to the pressed button 
void Game::handleButtonEvents(GameButtonFlags_t& event)
{
	sf::Clock timer;
	switch (event)
	{
	case Hint:
		this->m_stickContainer.showAvilables(m_window);
		break;
	case Save:
		this->saveGame();
		break;
	default:
		break;
	}
	this->m_states.addTime(timer.getElapsedTime().asSeconds());

	event = None;
}

//========================================
//this function saves the current game
void Game::saveGame() const
{
	std::string fileName = openFileDialog();
	std::ofstream gameFile(fileName);

	gameFile << this->m_stickContainer.getOgNumOfSticks() << "\n" <<
		this->m_states.getTime() << " " << this->m_states.getScore() << "\n";

	this->m_stickContainer.writeSticksData(gameFile);

	gameFile.close();
	
}
//=============================================================
void Game::checkWin(bool& win)
{
	if (m_stickContainer.isEmpty())
	{
		win = true;
	}
}
//=============================================================
// this function displays the end screen
void Game::showEndScreen(bool win) const
{
	ImageManager& manager = ImageManager::getInstance();
	sf::Sprite image;
	sf::Clock clock;
	int time = 3;

	win ? image.setTexture(manager.getImage("WinImage")) :
		image.setTexture(manager.getImage("LoseImage"));

	m_window.clear();
	m_window.draw(image);
	m_window.display();
	
	while ((int)clock.getElapsedTime().asSeconds() < time)
	{
	}
}
//=============================================================
void Game::loadBackground(sf::Sprite& background)
{
	ImageManager& manager = ImageManager::getInstance();

	background.setTexture(manager.getImage("GameBackground"));
}

