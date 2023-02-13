//
// Created by cx9ps3 on 12.02.23.
//

#include "Enemy.hpp"
#include <iostream>
#include <random>

void Enemy::start()
{
    Paddle::start();
}

void Enemy::update(float deltaTime)
{
    Paddle::update(deltaTime);
    move(deltaTime);
}
void Enemy::setBall(const std::shared_ptr<Ball> &ball)
{
    this->ball = ball;
}

void Enemy::setSpeed(int speed)
{
    this->speed = speed;
}

void Enemy::move(float deltaTime)
{
    sf::Vector2f position = getPosition();
    position.y += deltaTime  * ball->getVelocity().normalized().y * speed;
    if (position.y > 0 && position.y < windowSize.y - rectangleHeight)
    {
        setPosition(position);
    }
}
