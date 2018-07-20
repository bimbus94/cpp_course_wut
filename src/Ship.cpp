#include "Ship.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>



Ship::Ship()
    : ammo_type(1), ammo_amount(10), life_amount(5)
{

    //cout << "Konstruktor z lista inicjalizujaca z parametrami a " << endl;

}


Ship::Ship(const int& a_t, const int& a_a, const int& l_a)
    : ammo_type(a_t), ammo_amount(a_a), life_amount(l_a)
{

    //cout << "Konstruktor parametryczny z parametrami"<< endl;
}


Ship::~Ship()
{
    //cout << "Destruktor" << endl;
}


void Ship::setLifeAmount(int l_a) //ustawianie statku
{
    this->life_amount=l_a;
}

int Ship::getLifeAmount() //ustawianie statku
{
    return (this->life_amount);
}



//virtual bool Ship::shoot(int& sru)=0;

void Ship::getHurt() //sprawdzanie czy dostalem
{
    Ship::setLifeAmount(getLifeAmount()-1);
}


//virtual void Ship::moveShip(int& srututu)=0;



//virtual void Ship::dead()=0;

