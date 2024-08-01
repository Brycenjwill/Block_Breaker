#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//Player class
//Can: move- using user input left / right
//Has: Rectangle object, Position x & y
//Gives: Rectangel object, Position x & y
//Gets: User input (left / right, for: move), Window Properties (size x & y, for: move)


namespace P {

    class Player {

        sf::RectangleShape obj;

        int posx;
        int posy;
        int width;


     public :
        Player(sf::RectangleShape, sf::Vector2f Pos, int Width);
        void do_something();

        sf::Vector2f move(int dir, sf::Vector2f windowSize);
        sf::Vector2f getPos();
    };
}
