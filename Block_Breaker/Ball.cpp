#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Ball.h"
#include <stdlib.h>

using namespace std;
using namespace B;

Ball::Ball(sf::Vector2f startingPos, sf::RectangleShape object, int ballSize) {
	posx = startingPos.x;
	posy = startingPos.y;
	gameObj = object;
	direction = sf::Vector2f(0, 1);
	size = ballSize;

	//Maybe change speed later lol
	speed = 3;

	//Set angles that ball will do if it hits player
	angle["right"] = sf::Vector2f(1, -1);
	angle["farRight"] = sf::Vector2f(3, -1);
	angle["left"] = sf::Vector2f(-1, -1);
	angle["farLeft"] = sf::Vector2f(-3, -1);


	}

//Check if the ball can continue its current course
sf::Vector2f Ball::move(sf::Vector2f windowSize, sf::Vector2f playerPosition, sf::Vector2f playerSize) {
	int dirx = direction.x;
	int diry = direction.y;

	//If ball is touching player
	if ((posx >= playerPosition.x && posx <= playerPosition.x + playerSize.x) || (posx + size >= playerPosition.x && posx + size <= playerPosition.x + playerSize.x)) {
		if (posy + size >= playerPosition.y && posy + size <= playerPosition.y + playerSize.y) {

			//Get where the ball will hit the player
			int connectionPoint = abs((posx + size / 2) - playerPosition.x);

			//Check which of the four segments the ball is hitting on, and assign angle from the angle map.
			if (connectionPoint < playerSize.x / 4) {
				direction = angle["farLeft"];
				posx += direction.x * speed;
				posy += direction.y * speed;
			}
			else {
				if (connectionPoint < playerSize.x / 2) {
					direction = angle["left"];
					posx += direction.x * speed;
					posy += direction.y * speed;
					
					//Thats rough, buddy.
					posy -= size;
				}
				else {
					if (connectionPoint > playerSize.x - playerSize.x / 4) {
						direction = angle["farRight"];
						posx += direction.x * speed;
						posy += direction.y * speed;
					}
					else {
						direction = angle["right"];
						posx += direction.x * speed;
						posy += direction.y * speed;
					}
				}
			}
		}
	}

	//Move horizontally if possible
	if (posx + (dirx*speed) <= windowSize.x - size && posx + dirx >= 0) {
		posx += dirx * speed;
	}
	else {
		//When at right edge of screen
		if (posx + (dirx * speed) > windowSize.x - size) {
			direction = sf::Vector2f(dirx *= -1, diry);
			posx += direction.x * speed;
		}
		//When at left edge of screen
		if (posx + (dirx * speed) < 0) {
			direction = sf::Vector2f(dirx *= -1, diry);
			posx += direction.x * speed;
		}
	}
	
	if (posy + diry >= 0) {
		posy += diry * speed;
	}
	else {
		//Swap directions when hitting top of the screen
		direction = sf::Vector2f(dirx, diry *= -1);
	}

	//Remove later, code for seeting if ball is touching player



	return sf::Vector2f(posx, posy);
}

//Handle collision between player and ball
void Ball::bounce() {
	
}