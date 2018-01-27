#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
using namespace std;
#include <string>
#include "Bullet.hpp"
#include "Position.hpp"
#include "Ship.hpp"

class PlayerShip
    :public Ship, public Position//glowna wirtualna klasa, z ktorej beda dziedziczly inne rodzaje statkow
{

private:


public:

    PlayerShip();

    PlayerShip(const int&, const int&, const int&, const int&, const char&, const int&, const int&, const int&);

    ~PlayerShip();


    bool shoot(int&);

    void moveShip(int&);

    bool dead();

};

#endif
