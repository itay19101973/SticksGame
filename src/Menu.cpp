#include "Menu.h"

//=============================================================
//ctor
Menu::Menu()
{	
}

//=============================================================
// add buttons to the menu
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
// this function handles the button clicks of the menu
void Menu::handleClicks(const sf::Vector2f& mousePos,
	sf::RenderWindow& window , GameButtonFlags_t& flag) const
{
	try {
		for (const auto& [name, btn] : this->m_buttons)
		{
			if (btn->isClicked(mousePos))
			{
				btn->action(flag); // setting flag
				btn->action(window); // sometimes operates the action
			}
		}
	}
	// handelling exeptions
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
// this functions makes the buttons float when the mouse pass on them
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
