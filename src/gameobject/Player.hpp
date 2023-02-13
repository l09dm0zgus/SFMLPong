//
// Created by cx9ps3 on 11.02.23.
//

#ifndef PONG_PLAYER_HPP
#define PONG_PLAYER_HPP
#include "Paddle.hpp"

class Player : public Paddle
{
public:
    void start() override;
    void update(float deltaTime) override;
};


#endif//PONG_PLAYER_HPP
