//
// Created by cx9ps3 on 10.02.23.
//

#ifndef PONG_WINDOW_HPP
#define PONG_WINDOW_HPP
#include "../gameobject/Scene.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Window.hpp>
#include <memory>

class Window
{
public:
    Window(int width, int height, const std::string &windowTitle);
    bool isOpen();
    bool pollEvent(sf::Event &event);
    void render(const Scene &scene);
    void close();
    sf::Vector2u getSize() const;

private:
    std::shared_ptr<sf::RenderWindow> window;
};


#endif//PONG_WINDOW_HPP
