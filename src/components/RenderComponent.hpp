//
// Created by cx9ps3 on 10.02.23.
//

#ifndef PONG_RENDERCOMPONENT_HPP
#define PONG_RENDERCOMPONENT_HPP


#include "IComponent.hpp"
#include <SFML/Graphics.hpp>
class RenderComponent : public IComponent
{
public:
    virtual ~RenderComponent() = default;
    void start() override;
    void update(float deltaTime) override;
    virtual void setPosition(const sf::Vector2f &position) = 0;
    std::shared_ptr<sf::Drawable> getDrawable();

protected:
    std::shared_ptr<sf::Drawable> drawable;
    sf::Vector2f position;
};


#endif//PONG_RENDERCOMPONENT_HPP
