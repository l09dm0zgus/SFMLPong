
//
// Created by cx9ps3 on 10.02.23.
//

#ifndef PONG_GAMEOBJECT_HPP
#define PONG_GAMEOBJECT_HPP


#include "../components/IComponent.hpp"
#include "../components/RenderComponent.hpp"
#include "SFML/System/Vector2.hpp"
#include <memory>
#include <vector>

class GameObject
{
public:
    virtual void start();
    virtual void update(float deltaTime);
    void addComponent(const std::shared_ptr<IComponent> &component);
    void setPosition(const sf::Vector2f &position);
    void setWindowSize(const sf::Vector2u &windowSize);
    sf::Vector2f getPosition();
    std::vector<std::shared_ptr<RenderComponent>> getRenderComponents();

private:
    std::vector<std::shared_ptr<IComponent>> components;
    sf::Vector2f position;

protected:
    sf::Vector2u windowSize{0, 0};
};


#endif//PONG_GAMEOBJECT_HPP
