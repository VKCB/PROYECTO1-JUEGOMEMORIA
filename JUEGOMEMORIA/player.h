#include <QString>
#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    int puntos;
    int id;
    QString nombre;
public:
    Player();

    int getPuntos() const;
    void setPuntos(int newPuntos);
    void addPuntos(int points);
    int getId() const;
    void setId(int newId);
    const QString &getNombre() const;
    void setNombre(const QString &newNombre);
};

#endif // PLAYER_H
