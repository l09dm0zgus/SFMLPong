//
// Created by cx9ps3 on 13.02.23.
//

#ifndef PONG_SOUNDCOMPONENT_HPP
#define PONG_SOUNDCOMPONENT_HPP


#include "IComponent.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

class SoundComponent : public IComponent
{
public:
    SoundComponent(const std::string &pathToFile);
    void start() override;
    void update(float deltaTime) override;
    void play();

private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
};


#endif//PONG_SOUNDCOMPONENT_HPP
