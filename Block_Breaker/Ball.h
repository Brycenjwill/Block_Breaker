#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
//Ball
//Can: Move(direction), bounce off of bricks / wall, playerBounce
//Has: Locationx, Locationy, Vector2 direction, rectangle object
//Gives: Locaionx / y
// Gets: Window Size, playerpos, brick pos


namespace B {
	class Ball {

		int posx;
		int posy;
		int size;
		int speed;
		sf::Vector2f direction;
		sf::RectangleShape gameObj;
		map<string, sf::Vector2f> angle;


	public : 
		Ball(sf::Vector2f startingPos, sf::RectangleShape object, int ballSize);
		sf::Vector2f move(sf::Vector2f windowSize, sf::Vector2f playerPosition, sf::Vector2f playerSize);
		void bounce();
	};
}