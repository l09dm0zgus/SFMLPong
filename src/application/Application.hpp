//
// Created by cx9ps3 on 10.02.23.
//

#ifndef PONG_APPLICATION_HPP
#define PONG_APPLICATION_HPP

#include "../gameobject/Scene.hpp"

class Application
{
public:
    void run();

private:
    void loadScene(const class Window &window);
    Scene scene;
};


#endif//PONG_APPLICATION_HPP
