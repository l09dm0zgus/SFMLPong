//
// Created by cx9ps3 on 13.02.23.
//

#include "TextComponent.hpp"
#include <iostream>

TextComponent::TextComponent(const std::string &pathToFile, int fontSize, const sf::Color &color)
{

    if (!font.loadFromFile(pathToFile))
    {
        std::cout << "Failed to load file: " << pathToFile << std::endl;
        exit(-1);
    }
    text = std::make_shared<sf::Text>();
    text->setFont(font);
    text->setFillColor(color);
    text->setCharacterSize(fontSize);
    text->setStyle(sf::Text::Bold);
    drawable = text;
}

void TextComponent::setText(const std::string &text)
{
    this->text->setString(text);
}

void TextComponent::start()
{
    RenderComponent::start();
}

void TextComponent::update(float deltaTime)
{
    RenderComponent::update(deltaTime);
}

void TextComponent::setPosition(const sf::Vector2f &position)
{
    this->position = position;
    text->setPosition(position);
}
