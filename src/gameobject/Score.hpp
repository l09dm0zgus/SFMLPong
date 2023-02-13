//
// Created by cx9ps3 on 13.02.23.
//

#ifndef PONG_SCORE_HPP
#define PONG_SCORE_HPP


#include "../components/TextComponent.hpp"
#include "GameObject.hpp"

class Score : public GameObject
{
public:
    void start() override;
    void update(float deltaTime);
    void addScore();

private:
    std::shared_ptr<TextComponent> textComponent;
    int score{0};
};


#endif//PONG_SCORE_HPP
