#ifndef AlienShip_H
#define AlienShip_H
using namespace std;
#include <string>
#include "Position.hpp"
#include "Ship.hpp"

class AlienShip
    :public Ship, public Position//glowna wirtualna klasa, z ktorej beda dziedziczly inne rodzaje statkow
{

private:


public:

    AlienShip();

    AlienShip(const int&, const int&, const int&, const int&, const char&, const int&, const int&, const int&);

    ~AlienShip();


    bool shoot(int&);

    void moveShip(int&);

    void moveShipVertical(int&);

    bool dead();

};

#endif
