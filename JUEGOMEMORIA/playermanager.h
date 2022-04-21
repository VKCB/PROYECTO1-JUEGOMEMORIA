#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "player.h"
#include <QString>

class PlayerManager
{
    PlayerManager();
    static PlayerManager * instance;
    Player * player1;
    Player * player2;
    int currentPlayer;
    ~PlayerManager();
public:
    static PlayerManager * getInstance();

    int getCurrentPlayer() const;
    Player *getCurrentPlayerReference() const;
    void initFirstPlayer(QString name);
    void initSecondPlayer(QString name);
    void addCurrentPlayerPoints(int points);
    void setCurrentPlayer(int newCurrentPlayer);
    void nextPlayer();
    Player *getPlayer1() const;
    void setPlayer1(Player *newPlayer1);
    Player *getPlayer2() const;
    void setPlayer2(Player *newPlayer2);
};

#endif // PLAYERMANAGER_H
