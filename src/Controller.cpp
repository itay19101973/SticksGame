#include "Controller.h"

Controller::Controller() : m_menu()
{
}

void Controller::run()
{
	srand(time(NULL));

	sf::Vector2f mousePos;
	sf::RenderWindow window(sf::VideoMode(WINDOW_MANAGER_WIDTH,
		WINDOW_MANAGER_HEIGHT),
		"Sticks");

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		window.clear();

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
				m_menu.handleClicks(mousePos, window);
				break;

			case sf::Event::MouseMoved:

				sf::Event::MouseMoveEvent mouse = event.mouseMove;
				mousePos = window.mapPixelToCoords({ mouse.x, mouse.y });
				m_menu.handleFloating(mousePos);
			}
		}
	}
}