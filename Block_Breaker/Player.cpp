#include "Player.h"
#include <string>
#include <iostream>

using namespace std;
using namespace P;


//Assign default position on creation. Also, assign game object on creation
Player::Player(sf::RectangleShape object, sf::Vector2f pos, int Width) {
    posx = pos.x;
    posy = pos.y;
    width = Width;
    obj = object;
}


void Player::do_something()
{
    cout << posx << endl;
}

//Move player. Return new location to render
sf::Vector2f Player::move(int dir, sf::Vector2f windowSize) {
    int distance = 3;

    //Going right
    if (dir == 1 && posx + distance <= windowSize.x - width) {
        posx += distance;
    }
    //Going left
    if (dir == -1 && posx - distance >= 0) {
        posx -= distance;
    }



    return sf::Vector2f(posx, posy);
}

//Get position of player rectangle
sf::Vector2f Player::getPos() {
    return sf::Vector2f(posx, posy);
}