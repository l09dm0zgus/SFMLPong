//
// Created by cx9ps3 on 13.02.23.
//

#include "Score.hpp"

void Score::start()
{
    GameObject::start();
    textComponent = std::make_shared<TextComponent>("font.ttf", 72, sf::Color::White);
    textComponent->setText("0");
    addComponent(textComponent);
}

void Score::update(float deltaTime)
{
    GameObject::update(deltaTime);
}

void Score::addScore()
{
    score++;
    textComponent->setText(std::to_string(score));
}
