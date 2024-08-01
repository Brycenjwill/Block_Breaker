#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include <iostream>

using namespace std;
using namespace P;
using namespace B;

int main()
{
    sf::Vector2f windowSize = sf::Vector2f(400, 600);

    sf::RenderWindow window(sf::VideoMode(400, 600), "Block Breaker");
    window.setFramerateLimit(60);

    //Player setup
    int playerWidth = 40;
    sf::RectangleShape playerRect(sf::Vector2f(playerWidth, 10));
    sf::Vector2f defaultPlayerPos = sf::Vector2f((windowSize.x / 2) - (playerWidth / 2), 500);

    playerRect.setFillColor(sf::Color::Cyan);
    playerRect.setPosition(defaultPlayerPos);
    Player p(playerRect, defaultPlayerPos, 40);

    //Ball setup
    int ballSize = 5;
    sf::RectangleShape ballRect(sf::Vector2f(ballSize, ballSize));
    sf::Vector2f startingBallPos = sf::Vector2f((windowSize.x / 2) - (ballSize/ 2), 300);
    ballRect.setFillColor(sf::Color::White);
    ballRect.setPosition(startingBallPos);
    Ball b(startingBallPos, ballRect, ballSize);

    //Event handling
    bool moving = false; //Check if player should be moving
    int direction = 0; //Set direction player is moving. 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //When key is pressed, set player movement direction and set moving to true
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::Right) {
                    moving = true;
                    direction = 1;
                }
                if (event.key.scancode == sf::Keyboard::Scan::Left) {
                    moving = true;
                    direction = -1;
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.scancode == sf::Keyboard::Scan::Right && direction == 1) {
                    moving == false;
                    direction = 0;
                }
                if (event.key.scancode == sf::Keyboard::Scan::Left) {
                    moving == false;
                    direction = 0;
                }
            }
        }


        //Game logic

        //Move player
        if (moving) {
            playerRect.setPosition(p.move(direction, windowSize));
        }

        //Move ball
        ballRect.setPosition(b.move(windowSize, playerRect.getPosition(), playerRect.getSize()));
        
        
        


        //Clear previous window
        window.clear();

        //Draw gameobjects onto screen
        window.draw(ballRect);
        window.draw(playerRect);
        window.display();
    }

    return 0;
}