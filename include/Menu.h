#pragma once

#include <unordered_map>
#include "Button.h"
#include "PlayButton.h"
#include "ExitButton.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class Menu
{
public:
	Menu();
	~Menu() = default;

	void draw(sf::RenderWindow& window) const;
	void handleClicks(const sf::Vector2f& mousePos, sf::RenderWindow& window) const;
	void handleFloating(const sf::Vector2f& mousePos);


private:
	std::unordered_map<std::string, std::unique_ptr<Button>> m_buttons;
	sf::Sprite m_bgImg;
	
};
