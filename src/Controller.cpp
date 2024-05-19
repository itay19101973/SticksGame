#include "Controller.h"

Controller::Controller()
	: m_menu()
{
	ImageManager& manager = ImageManager::getInstance();
	this->m_bgImge = sf::Sprite(manager.getImage("Background"));
}

void Controller::addMenuButtons()

{
	ImageManager& manager = ImageManager::getInstance();
	this->m_menu.addButton(std::make_unique<PlayButton>(PLAY_BTN_POS, manager.getImage("PlayButton") ,
		MENU_BUTTON_DEFA_SIZE), "PlayButton");
	this->m_menu.addButton(std::make_unique<ExitButton>(EXIT_BTN_POS, manager.getImage("ExitButton") ,
		MENU_BUTTON_DEFA_SIZE)  , "ExitButton");
}

void Controller::run()
{
	srand(time(NULL));

	sf::Vector2f mousePos;
	sf::RenderWindow window(sf::VideoMode(WINDOW_MANAGER_WIDTH,
		WINDOW_MANAGER_HEIGHT),
		"Sticks");

	addMenuButtons();

	GameButtonFlags_t flag = None;


	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		window.clear();

		window.draw(this->m_bgImge);
		m_menu.draw(window);
		

		window.display();


		for (auto event = sf::Event{}; window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				window.close();
				break;

			case sf::Event::MouseButtonReleased:

				mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				m_menu.handleClicks(mousePos, window ,  flag);
				break;

			case sf::Event::MouseMoved:

				sf::Event::MouseMoveEvent mouse = event.mouseMove;
				mousePos = window.mapPixelToCoords({ mouse.x, mouse.y });
				m_menu.handleFloating(mousePos);
			}
		}
	}
}