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
	try {
		for (const auto& [name, btn] : this->m_buttons)
		{
			if (btn->isClicked(mousePos))
			{
				btn->action(flag);
				btn->action(window);
			}
		}
	}
	catch (const FileException& e) {

		std::cerr << "File error: " << e.what() << std::endl;
	}
	catch (const WrongInputException& e) {
		std::cerr << "File format error: " << e.what() << std::endl;
	}
	catch (const TimeException& e) {
		std::cerr << "Time error: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


}

//======================================================
void Menu::handleFloating(const sf::Vector2f& mousePos)
{
	for (const auto& [name, btn] : this->m_buttons)
	{
		if (btn->isFloatedOn(mousePos))
		{
			btn->scale(btn -> getFloatedSize());
		}
		else
		{
			btn->scale(btn -> getDefSize());
		}
	}
}
