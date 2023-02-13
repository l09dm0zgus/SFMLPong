//
// Created by cx9ps3 on 13.02.23.
//

#include "Border.hpp"
#include "../components/RectangleComponent.hpp"

void Border::start()
{
    GameObject::start();
    addComponent(std::make_shared<RectangleComponent>(10, windowSize.y, sf::Color::White));
}

void Border::update(float deltaTime)
{
    GameObject::update(deltaTime);
}
