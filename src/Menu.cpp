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
	sf::RenderWindow& window) const
{
	bool flag;
	for (const auto& [name, btn] : this->m_buttons)
	{
		if (btn->isClicked(mousePos))
		{
			btn->action(window , flag);
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
