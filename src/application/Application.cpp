//
// Created by cx9ps3 on 10.02.23.
//

#include "Application.hpp"
#include "../gameobject/Ball.hpp"
#include "../gameobject/Border.hpp"
#include "../gameobject/Enemy.hpp"
#include "../gameobject/Player.hpp"
#include "../gameobject/Score.hpp"
#include "../gameobject/ScoreObserver.hpp"
#include "../window/Window.hpp"
#include <iostream>

void Application::run()
{
    Window window(800, 600, "Pong");
    loadScene(window);
    scene.start();
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        sf::Time dt = deltaClock.restart();
        float deltaTime = dt.asSeconds();
        scene.update(deltaTime);
        window.render(scene);
    }
}

void Application::loadScene(const Window &window)
{
    std::shared_ptr<Player> player = std::make_shared<Player>();
    std::shared_ptr<Ball> ball = std::make_shared<Ball>();
    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
    std::shared_ptr<Border> border = std::make_shared<Border>();
    std::shared_ptr<Score> playerScore = std::make_shared<Score>();
    std::shared_ptr<Score> enemyScore = std::make_shared<Score>();
    std::shared_ptr<ScoreObserver> scoreObserver = std::make_shared<ScoreObserver>();

    playerScore->setPosition(sf::Vector2f((window.getSize().x / 2) - 140.0f, 10));
    scene.addGameObject(playerScore);

    enemyScore->setPosition(sf::Vector2f((window.getSize().x / 2) + 40.0f, 10));
    scene.addGameObject(enemyScore);

    scoreObserver->setEnemyScore(enemyScore);
    scoreObserver->setPlayerScore(playerScore);

    player->setPosition(sf::Vector2f(0, window.getSize().y / 2));
    player->setWindowSize(window.getSize());
    scene.addGameObject(player);

    ball->setPlayer(player);
    ball->setWindowSize(window.getSize());
    ball->setPosition(sf::Vector2f(400, 300));
    ball->setEnemy(enemy);
    ball->setScoreObserver(scoreObserver);
    scene.addGameObject(ball);

    enemy->setBall(ball);
    enemy->setWindowSize(window.getSize());
    enemy->setPosition(sf::Vector2f(780, window.getSize().y / 2));
    enemy->setSpeed(260.0f);
    scene.addGameObject(enemy);

    border->setPosition(sf::Vector2f(window.getSize().x / 2, 0));
    border->setWindowSize(window.getSize());
    scene.addGameObject(border);
}
