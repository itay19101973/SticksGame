#include "Menu.h"

Menu::Menu()
{	
}


void Menu::addButton(std::unique_ptr<Button> button , std::string name)
{
	m_buttons[name] = std::move(button);
}

//======================================================
void Menu::draw(sf::RenderWindow& window) const
{
	
	for (const auto& [name, btn] : this->m_buttons)
	{
		btn->draw(window);
	}

}

//======================================================
void Menu::handleClicks(const sf::Vector2f& mousePos,
	sf::RenderWindow& window , GameButtonFlags_t& flag) const
{
	for (const auto& [name, btn] : this->m_buttons)
	{
		if (btn->isClicked(mousePos))
		{
			btn->action(flag);
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
			btn->scale(MENU_BUTTON_DEFA_SIZE);
		}
	}
}
