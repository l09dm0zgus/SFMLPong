//
// Created by cx9ps3 on 10.02.23.
//

#ifndef PONG_ICOMPONENT_HPP
#define PONG_ICOMPONENT_HPP

class IComponent
{
public:
    virtual ~IComponent() = default;
    virtual void start() = 0;
    virtual void update(float deltaTime) = 0;
};

#endif//PONG_ICOMPONENT_HPP
