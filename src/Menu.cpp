#include "Menu.h"

Menu::Menu()
{
	ImageManager& manager = ImageManager::getInstance();

	this->m_buttons["PlayButton"] = std::make_unique<PlayButton>(PLAY_BTN_POS, manager.getImage("PlayButton"));
	this->m_buttons["ExitButton"] = std::make_unique<ExitButton>(EXIT_BTN_POS, manager.getImage("ExitButton"));
	this->m_bgImg = sf::Sprite(manager.getImage("Background"));
}


//======================================================
void Menu::draw(sf::RenderWindow& window) const
{

	window.draw(m_bgImg);
	
	for (const auto& [name, btn] : this->m_buttons)
	{
		btn->draw(window);
	}

}

//======================================================
void Menu::handleClicks(const sf::Vector2f& mousePos,
	sf::RenderWindow& window) const
{
	for (const auto& [name, btn] : this->m_buttons)
	{
		if (btn->isClicked(mousePos))
		{
			btn->action(window);
		}
	}
}

//======================================================
void Menu::handleFloating(const sf::Vector2f& mousePos)
{
	for (const auto& [name, btn] : this->m_buttons)
	{
		if (btn->isFloatedOn(mousePos))
		{
			btn->scale(BUTTON_FLOATED_SIZE);
		}
		else
		{
			btn->scale(BUTTON_DEFA_SIZE);
		}
	}
}
