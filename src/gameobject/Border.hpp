//
// Created by cx9ps3 on 13.02.23.
//

#ifndef PONG_BORDER_HPP
#define PONG_BORDER_HPP


#include "GameObject.hpp"

class Border : public GameObject
{
public:
    void start() override;
    void update(float deltaTime) override;
};


#endif//PONG_BORDER_HPP
