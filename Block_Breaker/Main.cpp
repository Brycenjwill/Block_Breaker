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


    //Generate and store bricks
    int brickWidth = 40;
    int brickHeight = 20;
    sf::Color colors[6] = { sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Yellow, sf::Color::Red, sf::Color::Blue };

    //Store the "bricks" by their location.
    sf::RectangleShape bricks[60];
    int j = 0;
    int sub = 0;
    int layer = 0;
    for (int i = 0; i < 60; i++) {
        if (j >= 10){
            sub += windowSize.x;
            j = 0;
            layer += 1;
        }
        sf::RectangleShape brick(sf::Vector2f(brickWidth, brickHeight));
        brick.setFillColor(colors[layer]);
        brick.setPosition(sf::Vector2f(0 + i * 40 - sub, layer * brickHeight));
        brick.setOutlineColor(sf::Color::Black);
        brick.setOutlineThickness(3);
        bricks[i] = brick;
        j += 1;
    }

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
                    moving = false;
                    direction = 0;
                }
                if (event.key.scancode == sf::Keyboard::Scan::Left) {
                    moving = false;
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
        ballRect.setPosition(b.move(windowSize, playerRect.getPosition(), playerRect.getSize(),  bricks));
        
        
        


        //Clear previous window
        window.clear();

        //Draw gameobjects onto screen
        for (int i = 0; i < (sizeof(bricks) / sizeof(bricks[0])); i++) {
            window.draw(bricks[i]);
        }
        window.draw(ballRect);
        window.draw(playerRect);

        window.display();
    }

    return 0;
}