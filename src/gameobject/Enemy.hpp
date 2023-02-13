//
// Created by cx9ps3 on 12.02.23.
//

#ifndef PONG_ENEMY_HPP
#define PONG_ENEMY_HPP

#include "Ball.hpp"
#include "Paddle.hpp"

class Enemy : public Paddle
{
public:
    void start() override;
    void update(float deltaTime) override;
    void setBall(const std::shared_ptr<Ball> &ball);
    void setSpeed(int speed);

private:
    std::shared_ptr<Ball> ball;
    void move(float deltaTime);
};


#endif//PONG_ENEMY_HPP
