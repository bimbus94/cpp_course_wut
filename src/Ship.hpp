#ifndef SHIP_H
#define SHIP_H
using namespace std;
#include <string>


class Ship

{

protected:

    int ammo_type; // tu bedzie odnosic sie do typu amunicji z oddzielnej klasy docelowo wirtualna
    int ammo_amount; //ilosc amunicji docelowo modyfikowana przez jakies zakupy i zestrzelania
    int life_amount; //liczba zyc docelowo modyfikowana przez jakies zestrzelnia itp tez moze wirtualna w zaleznosci od typu statku



public:

    Ship();

    Ship(const int&, const int&, const int&);

    ~Ship();


    void setLifeAmount(int);

    int getLifeAmount();

    virtual bool shoot(int&)=0;

    void getHurt();

    virtual void moveShip(int&)=0;

    virtual bool dead()=0;

};

#endif
