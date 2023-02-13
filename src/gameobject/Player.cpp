//
// Created by cx9ps3 on 11.02.23.
//

#include "Player.hpp"


void Player::start()
{
    Paddle::start();
}

void Player::update(float deltaTime)
{
    Paddle::update(deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        move(-1, deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        move(1, deltaTime);
    }
}
