#include "PlayerShip.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>



PlayerShip::PlayerShip()
    : Position(20,18,1,1,'A'),Ship(1,10,5)
{

    //cout << "Konstruktor z lista inicjalizujaca z parametrami a " << endl;

}


PlayerShip::PlayerShip(const int& xx, const int& yy, const int &w, const int& h, const char& s_a, const int& a_t, const int& a_a, const int& l_a)
    : Position(xx,yy,w,h,s_a), Ship(a_t, a_a, l_a)
{

    //cout << "Konstruktor parametryczny z parametrami"<< endl;
}


PlayerShip::~PlayerShip()
{
    //cout << "Destruktor" << endl;
}



bool PlayerShip::shoot(int& KeyBoardPress) //wystrzelenie pocisku
{
    if (KeyBoardPress==32) //klawisz spacji
    {
        //tu tworze nowa bombe
        //cout<<"Tworze nowy pocisk"<<endl;
        return true;
        //wyslij info do BulletPack
    }
    return false;
}



void PlayerShip::moveShip(int& KeyBoardPress) //ruch statekiem w zaleznosci od klawiatury
{
    if ((KeyBoardPress==97) && (getPositionX()-1)>1) //klawisz A
    {
        setPositionX(getPositionX()-1);
        cout<<getPositionX()<<endl;
    }
    else if ((KeyBoardPress==100) &&  (getPositionX()+1)<49)//klawisz D
    {
        setPositionX(getPositionX()+1);
        cout<<getPositionX()<<endl;
    }

}

bool PlayerShip::dead() // zniszczenie
{
    if(getLifeAmount()==0)
    {
        return true;
    }
    return false;
//cout<<'GameOver'<<endl;

//proces zniszczenia!!!
//gameover itp
};

