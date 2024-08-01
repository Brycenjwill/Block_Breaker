#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;

class Brick
{
	int posx;
	int posy;

	public:
		Brick();
		sf::Vector2f getPosition();
};

