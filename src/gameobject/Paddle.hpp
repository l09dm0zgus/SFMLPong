//
// Created by cx9ps3 on 12.02.23.
//

#ifndef PONG_PADDLE_HPP
#define PONG_PADDLE_HPP


#include "GameObject.hpp"

class Paddle : public GameObject
{
public:
    ~Paddle() = default;
    virtual void start() override;
    virtual void update(float deltaTime) override;
    std::shared_ptr<sf::RectangleShape> getRectangleShape();

protected:
    virtual void move(int value, float deltaTime);
    float speed{250.0f};
    float rectangleWidth{20};
    float rectangleHeight{60};
    std::shared_ptr<class RectangleComponent> rectangleComponent;
};


#endif//PONG_PADDLE_HPP
