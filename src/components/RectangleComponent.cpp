//
// Created by cx9ps3 on 11.02.23.
//

#include "RectangleComponent.hpp"

RectangleComponent::RectangleComponent(float width, float height, const sf::Color &color)
{
    rectangleShape = std::make_shared<sf::RectangleShape>();
    rectangleShape->setSize(sf::Vector2f(width, height));
    rectangleShape->setOutlineColor(color);
    rectangleShape->setFillColor(color);
    drawable = rectangleShape;
}

void RectangleComponent::start()
{
    RenderComponent::start();
}

void RectangleComponent::update(float deltaTime)
{
    RenderComponent::update(deltaTime);
}

std::shared_ptr<sf::RectangleShape> RectangleComponent::getRectangleShape()
{
    return std::dynamic_pointer_cast<sf::RectangleShape>(drawable);
}

void RectangleComponent::setPosition(const sf::Vector2f &position)
{
    this->position = position;
    rectangleShape->setPosition(position);
}
