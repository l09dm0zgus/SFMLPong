//
// Created by cx9ps3 on 11.02.23.
//

#ifndef PONG_RECTANGLECOMPONENT_HPP
#define PONG_RECTANGLECOMPONENT_HPP


#include "RenderComponent.hpp"

class RectangleComponent : public RenderComponent
{
public:
    RectangleComponent(float width, float height, const sf::Color &color);
    void start() override;
    void update(float deltaTime) override;
    std::shared_ptr<sf::RectangleShape> getRectangleShape();
    void setPosition(const sf::Vector2f &position) override;

private:
    std::shared_ptr<sf::RectangleShape> rectangleShape;
};


#endif//PONG_RECTANGLECOMPONENT_HPP
