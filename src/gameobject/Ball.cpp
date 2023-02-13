//
// Created by cx9ps3 on 11.02.23.
//

#include "Ball.hpp"
#include "../components/RectangleComponent.hpp"
#include "../components/SoundComponent.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "ScoreObserver.hpp"
#include <random>

void Ball::update(float deltaTime)
{
    GameObject::update(deltaTime);
    checkCollisions(deltaTime);
}

void Ball::start()
{
    GameObject::start();
    rectangleComponent = std::make_shared<RectangleComponent>(rectangleWidth, rectangleHeight, sf::Color::White);
    hitSound = std::make_shared<SoundComponent>("s1.wav");
    addingScoreSound = std::make_shared<SoundComponent>("s2.wav");
    addComponent(rectangleComponent);
}

void Ball::move(float deltaTime, sf::Vector2f &position)
{
    if (!checkIfOut(position))
    {
        position += (velocity * deltaTime);
        setPosition(position);
    }
}

CollisionType Ball::intersects(std::shared_ptr<sf::RectangleShape> rectangleShape)
{
    sf::Rect<float> rect1 = this->rectangleComponent->getRectangleShape()->getGlobalBounds();
    sf::Rect<float> rect2 = rectangleShape->getGlobalBounds();
    std::optional<sf::Rect<float>> result = rect1.findIntersection(rect2);
    if (result)
    {
        if (rect2.top + rect2.height / 2 > rect1.top)
        {
            return TOP;
        }
        else if (rect2.top + rect2.height / 2 < rect1.top)
        {
            return BOTTOM;
        }
    }
    return NONE;
}

void Ball::setPlayer(std::shared_ptr<Player> &player)
{
    this->player = player;
}

void Ball::checkCollisions(float deltaTime)
{
    sf::Vector2f position = getPosition();
    move(deltaTime, position);

    if (intersects(player->getRectangleShape()) == CollisionType::TOP || intersects(enemy->getRectangleShape()) == CollisionType::TOP)
    {
        velocity.y = -0.75f * speed;
        velocity.x = -velocity.x;
        hitSound->play();
    }
    if (intersects(player->getRectangleShape()) == CollisionType::BOTTOM || intersects(enemy->getRectangleShape()) == CollisionType::BOTTOM)
    {
        velocity.y = 0.75f * speed;
        velocity.x = -velocity.x;
        hitSound->play();
    }
    if (position.y < 0 || position.y > windowSize.y + rectangleHeight)
    {
        velocity.y = -velocity.y;
        hitSound->play();
    }
}

bool Ball::checkIfOut(const sf::Vector2f &position)
{
    if (position.x > windowSize.x)
    {
        scoreObserver->onNotify(ScoreType::PLAYER);
        restorePosition();
        return true;
    }
    else if (position.x < 0)
    {
        scoreObserver->onNotify(ScoreType::ENEMY);
        restorePosition();
        return true;
    }
    return false;
}

void Ball::restorePosition()
{
    setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
    velocity.x = -velocity.x;
    velocity.y = 0;
    addingScoreSound->play();
}

sf::Vector2f Ball::getVelocity()
{
    return velocity;
}

void Ball::setEnemy(const std::shared_ptr<Enemy> &enemy)
{
    this->enemy = enemy;
}

void Ball::setScoreObserver(const std::shared_ptr<ScoreObserver> &scoreObserver)
{
    this->scoreObserver = scoreObserver;
}
