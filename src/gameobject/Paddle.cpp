//
// Created by cx9ps3 on 12.02.23.
//

#include "Paddle.hpp"
#include "../components/RectangleComponent.hpp"

void Paddle::start()
{
    GameObject::start();
    rectangleComponent = std::make_shared<RectangleComponent>(rectangleWidth, rectangleHeight, sf::Color::White);
    addComponent(rectangleComponent);
}

void Paddle::update(float deltaTime)
{
    GameObject::update(deltaTime);
}

std::shared_ptr<sf::RectangleShape> Paddle::getRectangleShape()
{
    return rectangleComponent->getRectangleShape();
}

void Paddle::move(int value, float deltaTime)
{
    sf::Vector2f position = getPosition();
    position.y = position.y + (value * speed * deltaTime);
    if (position.y > 0 && position.y < windowSize.y - rectangleHeight)
    {
        setPosition(position);
    }
}
