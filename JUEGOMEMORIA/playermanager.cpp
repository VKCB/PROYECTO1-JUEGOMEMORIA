#include "playermanager.h"

PlayerManager * PlayerManager::instance = 0;

PlayerManager::PlayerManager()
{
    currentPlayer = 1;
}

Player *PlayerManager::getPlayer2() const
{
    return player2;
}

void PlayerManager::setPlayer2(Player *newPlayer2)
{
    player2 = newPlayer2;
}

Player *PlayerManager::getPlayer1() const
{
    return player1;
}

void PlayerManager::setPlayer1(Player *newPlayer1)
{
    player1 = newPlayer1;
}

PlayerManager::~PlayerManager()
{

}

int PlayerManager::getCurrentPlayer() const
{
    return currentPlayer;
}

Player *PlayerManager::getCurrentPlayerReference() const
{
    return (currentPlayer==1)?player1:player2;
}

void PlayerManager::initFirstPlayer(QString name)
{
    player1 = new Player();
    player1->setNombre(name);
    player1->setId(1);
    player1->setPuntos(0);
}

void PlayerManager::initSecondPlayer(QString name)
{
    player2 = new Player();
    player2->setNombre(name);
    player2->setId(1);
    player2->setPuntos(0);
}

void PlayerManager::addCurrentPlayerPoints(int points)
{
    if (currentPlayer == 1) player1->addPuntos(points);
    else player2->addPuntos(points);
}

void PlayerManager::setCurrentPlayer(int newCurrentPlayer)
{
    currentPlayer = newCurrentPlayer;
}

void PlayerManager::nextPlayer()
{
    currentPlayer = (currentPlayer==1)?2:1;
}

PlayerManager *PlayerManager::getInstance()
{
    if (!instance) instance = new PlayerManager();
    return instance;
}
