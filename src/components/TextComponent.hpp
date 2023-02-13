//
// Created by cx9ps3 on 13.02.23.
//

#ifndef PONG_TEXTCOMPONENT_HPP
#define PONG_TEXTCOMPONENT_HPP


#include "RenderComponent.hpp"

class TextComponent : public RenderComponent
{
public:
    TextComponent(const std::string &pathToFile, int fontSize, const sf::Color &color);
    void setText(const std::string &text);
    void start() override;
    void update(float deltaTime);
    void setPosition(const sf::Vector2f &position) override;

private:
    std::shared_ptr<sf::Text> text;
    sf::Font font;
};


#endif//PONG_TEXTCOMPONENT_HPP
