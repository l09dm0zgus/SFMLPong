//
// Created by cx9ps3 on 13.02.23.
//

#include "ScoreObserver.hpp"

void ScoreObserver::setPlayerScore(std::shared_ptr<Score> &playerScore)
{
    this->playerScore = playerScore;
}

void ScoreObserver::setEnemyScore(std::shared_ptr<Score> &enemyScore)
{
    this->enemyScore = enemyScore;
}

void ScoreObserver::onNotify(ScoreType scoreType)
{
    switch (scoreType)
    {
        case ENEMY:
            enemyScore->addScore();
            break;
        case PLAYER:
            playerScore->addScore();
            break;
    }
}
