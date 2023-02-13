//
// Created by cx9ps3 on 10.02.23.
//

#include "GameObject.hpp"
#include "../components/RenderComponent.hpp"

void GameObject::update(float deltaTime)
{
    for (auto &component: components)
    {
        component->update(deltaTime);
    }
}

void GameObject::start()
{
    for (auto &component: components)
    {
        component->start();
    }
}

void GameObject::addComponent(const std::shared_ptr<IComponent> &component)
{
    components.push_back(component);
    setPosition(position);
}

void GameObject::setPosition(const sf::Vector2f &position)
{
    this->position = position;
    for (auto &component: components)
    {
        RenderComponent *renderComponent = dynamic_cast<RenderComponent *>(component.get());
        if (renderComponent != nullptr)
        {
            renderComponent->setPosition(position);
        }
    }
}

std::vector<std::shared_ptr<RenderComponent>> GameObject::getRenderComponents()
{
    std::vector<std::shared_ptr<RenderComponent>> renderComponents;
    for (auto &component: components)
    {
        std::shared_ptr<RenderComponent> renderComponent = std::dynamic_pointer_cast<RenderComponent>(component);
        if (renderComponent != nullptr)
        {
            renderComponents.push_back(renderComponent);
        }
    }
    return renderComponents;
}

sf::Vector2f GameObject::getPosition()
{
    return position;
}

void GameObject::setWindowSize(const sf::Vector2u &windowSize)
{
    this->windowSize = windowSize;
}
