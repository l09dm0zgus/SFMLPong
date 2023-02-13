//
// Created by cx9ps3 on 11.02.23.
//

#include "Scene.hpp"

std::vector<std::shared_ptr<RenderComponent>> Scene::getRenderComponents() const
{
    std::vector<std::shared_ptr<RenderComponent>> allGameObjectsRenderComponents;
    for (auto &gameObject: gameObjects)
    {
        std::vector<std::shared_ptr<RenderComponent>> gameObjectRenderComponents = gameObject->getRenderComponents();
        if (gameObjectRenderComponents.size() != 0)
        {
            std::copy(gameObjectRenderComponents.begin(), gameObjectRenderComponents.end(), std::back_inserter(allGameObjectsRenderComponents));
        }
    }
    return allGameObjectsRenderComponents;
}

void Scene::start()
{
    for (auto &gameObject: gameObjects)
    {
        gameObject->start();
    }
}

void Scene::update(float deltaTime)
{
    for (auto &gameObject: gameObjects)
    {
        gameObject->update(deltaTime);
    }
}

void Scene::addGameObject(const std::shared_ptr<GameObject> &gameObject)
{
    gameObjects.push_back(gameObject);
}
