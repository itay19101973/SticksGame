#pragma once

#include <iostream> 
#include <SFML/Graphics.hpp> // Include SFML header for sf::Vector2f
#include <windows.h>
using Point = sf::Vector2f;

bool onSegment(Point p, Point q, Point r);
int orientation(Point p, Point q, Point r);
bool doIntersect(Point p1, Point q1, Point p2, Point q2);
int getStickScore(const sf::Color& color);


std::string openFileDialog();