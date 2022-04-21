#include "player.h"

int Player::getPuntos() const
{
    return puntos;
}

void Player::setPuntos(int newPuntos)
{
    puntos = newPuntos;
}

void Player::addPuntos(int points)
{
    puntos += points;
}

int Player::getId() const
{
    return id;
}

void Player::setId(int newId)
{
    id = newId;
}

const QString &Player::getNombre() const
{
    return nombre;
}

void Player::setNombre(const QString &newNombre)
{
    nombre = newNombre;
}

Player::Player()
{

}
