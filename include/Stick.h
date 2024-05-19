#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <vector>
#include <memory>
#include <cmath>
#include <numbers>
#include "Utils.h"

class Stick
{
public:
	Stick();
	void addBlocker(std::shared_ptr<Stick>& blocker);
	void draw(sf::RenderWindow& window);
	bool liftable() const;
	bool isClicked(const sf::Vector2f& mousePos) const;
	bool isIntersect(const std::shared_ptr<Stick>& other) const;
	void updateBlockers(std::shared_ptr<Stick> stickToRemove);
	int getScore() const;

	class comperator {
	public:
		bool operator()(const std::shared_ptr<Stick>& stick1,
			const std::shared_ptr<Stick>& stick2) const;
	};

private:
	sf::RectangleShape m_stick;
	std::vector<std::shared_ptr<Stick>> m_blocking;
	sf::Vector2f m_endPoint;
	int m_score;
	
};

bool operator==(const Stick& stick1, const Stick& stick2);
bool operator<(const Stick& stick1, const Stick& stick2);
bool operator<=(const Stick& stick1, const Stick& stick2);