//
// Created by cx9ps3 on 13.02.23.
//

#ifndef PONG_SCOREOBSERVER_HPP
#define PONG_SCOREOBSERVER_HPP

#include "Score.hpp"

enum ScoreType
{
    PLAYER,
    ENEMY
};

class ScoreObserver
{
public:
    void setPlayerScore(std::shared_ptr<Score> &playerScore);
    void setEnemyScore(std::shared_ptr<Score> &enemyScore);
    void onNotify(ScoreType scoreType);

private:
    std::shared_ptr<Score> playerScore;
    std::shared_ptr<Score> enemyScore;
};


#endif//PONG_SCOREOBSERVER_HPP
