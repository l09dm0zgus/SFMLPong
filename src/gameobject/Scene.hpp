//
// Created by cx9ps3 on 11.02.23.
//

#ifndef PONG_SCENE_HPP
#define PONG_SCENE_HPP
#include "GameObject.hpp"
#include <memory>

class Scene
{
public:
    void start();
    void update(float deltaTime);
    void addGameObject(const std::shared_ptr<GameObject> &gameObject);
    std::vector<std::shared_ptr<RenderComponent>> getRenderComponents() const;

private:
    std::vector<std::shared_ptr<GameObject>> gameObjects;
};


#endif//PONG_SCENE_HPP
