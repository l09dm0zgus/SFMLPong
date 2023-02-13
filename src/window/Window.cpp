//
// Created by cx9ps3 on 10.02.23.
//

#include "Window.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include <algorithm>
Window::Window(int width, int height, const std::string &windowTitle)
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(sf::Vector2u(width, height)), windowTitle);
}

bool Window::isOpen()
{
    return window->isOpen();
}

bool Window::pollEvent(sf::Event &event)
{
    return window->pollEvent(event);
}

void Window::close()
{
    window->close();
}


void Window::render(const Scene &scene)
{
    std::vector<std::shared_ptr<RenderComponent>> componentsToDraw = scene.getRenderComponents();
    window->clear();
    std::for_each(componentsToDraw.begin(), componentsToDraw.end(), [this](const std::shared_ptr<RenderComponent> renderComponent) {
        window->draw(*renderComponent->getDrawable());
    });
    window->display();
}

sf::Vector2u Window::getSize() const
{
    return window->getSize();
}
