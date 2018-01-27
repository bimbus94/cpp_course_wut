#include "AlienShip.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>




AlienShip::AlienShip()
    : Position(25,4,1,1,'V'),Ship(1,1,1)
{


    //cout << "Konstruktor z lista inicjalizujaca z parametrami a " << endl;

}


AlienShip::AlienShip(const int& xx, const int& yy, const int &w, const int& h, const char& s_a, const int& a_t, const int& a_a, const int& l_a)
    : Position(xx,yy,w,h,s_a), Ship(a_t, a_a, l_a)
{
    std::srand( time( NULL ) );
    //cout << "Konstruktor parametryczny z parametrami"<< endl;
}


AlienShip::~AlienShip()
{
    //cout << "Destruktor" << endl;
}



bool AlienShip::shoot(int& s_p) //wystrzelenie pocisku /s_p wspolczynnik czestotliwosci strzelania
{
    int i; // podziałka czasowa

    int sh_p =( std::rand() % 100 ) + 1;
    if (sh_p>s_p)
    {

        //tu tworze nowa bombe
        //cout<<"Tworze nowy pocisk"<<endl;
        return true;
        //wyslij info do BulletPack
    }
    return false;
}



void AlienShip::moveShip(int& s_p) //ruch kosmity
{
    int maximalX=48;
    int sh_p =( std::rand() % 100 ) + 1;
    if ( (sh_p>s_p) && ((getPositionX()-1)>2 ) )
    {
        setPositionX(getPositionX()-1);
        cout<<getPositionX()<<endl;
    }
    else if( (sh_p<s_p) && ((getPositionX()+1)<maximalX))
    {
        setPositionX(getPositionX()+1);
        cout<<getPositionX()<<endl;
    }
    ;
}

void AlienShip::moveShipVertical(int& step)
{
    int maximalY=20;


    if ((getPositionY()+step)<maximalY)
    {
        cout<<getPositionY()+step<<endl;
        setPositionY(getPositionY()+step);
    }

}

bool AlienShip::dead() // zniszczenie
{

    {

//proces zniszczenia!!!
//gameover itp
    }
}
