#ifndef BULLET_H
#define BULLET_H
#include "Position.hpp"
class Bullet
    :public Position//klasa matka pociskow , docelowo kilka typow pociskow
{
private:
    bool directionFromPlayer; //kierunek z ktorego leca naboje -true od gracza, -false od kosmitow
public:

    Bullet();

    Bullet(const int&, const int&,const int&, const int&, const char&, bool);

    ~Bullet();

    void moveBullet();
    bool getDir();


};
#endif
