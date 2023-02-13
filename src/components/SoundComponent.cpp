//
// Created by cx9ps3 on 13.02.23.
//

#include "SoundComponent.hpp"
#include <iostream>

void SoundComponent::start()
{
}

void SoundComponent::update(float deltaTime)
{
}

SoundComponent::SoundComponent(const std::string &pathToFile)
{
    if (!buffer.loadFromFile(pathToFile))
    {
        std::cout << "Failed to load file : " << pathToFile << std::endl;
        exit(-1);
    }
}

void SoundComponent::play()
{
    sound.setBuffer(buffer);
    sound.play();
}
