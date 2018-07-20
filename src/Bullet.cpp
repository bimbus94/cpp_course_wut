using namespace std;
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Bullet.hpp"

Bullet::Bullet() {}

Bullet::Bullet(const int& xx, const int& yy, const int& w, const int& h, const char& s_a, bool dir)
    :Position(xx,yy,w,h,s_a), directionFromPlayer(dir) //directionFromPlayer -true strzal od gracza, -false strzal od kosmitow
{}

Bullet::~Bullet() {}

void Bullet::moveBullet()
{
    if(directionFromPlayer)
    {
        this->setPositionY(this->getPositionY()-1);
    }
    else// if(directionFromPlayer==false)
    {
        this->setPositionY(this->getPositionY()+1);
    }
}

bool Bullet::getDir()
{
    return directionFromPlayer;
}



