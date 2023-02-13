//
// Created by cx9ps3 on 11.02.23.
//

#ifndef PONG_BALL_HPP
#define PONG_BALL_HPP
#include "GameObject.hpp"

enum CollisionType
{
    TOP,
    BOTTOM,
    NONE
};

class Ball : public GameObject
{
public:
    void start() override;
    void update(float deltaTime) override;
    void setPlayer(std::shared_ptr<class Player> &player);
    void setEnemy(const std::shared_ptr<class Enemy> &enemy);
    void setScoreObserver(const std::shared_ptr<class ScoreObserver> &scoreObserver);
    sf::Vector2f getVelocity();

private:
    CollisionType intersects(std::shared_ptr<sf::RectangleShape> rectangleShape);
    void move(float deltaTime, sf::Vector2f &position);
    void checkCollisions(float deltaTime);
    bool checkIfOut(const sf::Vector2f &position);
    void restorePosition();
    sf::Vector2f velocity{300, 0};
    float speed{300};
    std::shared_ptr<class Player> player;
    std::shared_ptr<class Enemy> enemy;
    std::shared_ptr<class RectangleComponent> rectangleComponent;
    std::shared_ptr<class ScoreObserver> scoreObserver;
    std::shared_ptr<class SoundComponent> hitSound;
    std::shared_ptr<class SoundComponent> addingScoreSound;
    float rectangleWidth{20};
    float rectangleHeight{20};
};


#endif //PONG_BALL_HPP
