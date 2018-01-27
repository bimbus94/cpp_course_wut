#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "GameMap.hpp"
#include "Bullet.hpp"
#include "PlayerShip.hpp"
#include "Position.hpp"
#include "AlienShip.hpp"
#include "AlienPack.hpp"
#include "BulletPack.hpp"
#include <unistd.h>   //_getch*/
#include <termios.h>  //_getch*/
#include <sys/ioctl.h>
using namespace std;



char getch()
{
    /*#include <unistd.h>   //_getch*/
    /*#include <termios.h>  //_getch*/
    char buf=0;
    struct termios old= {0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    //printf("%c\n",buf);
    return buf;
}




bool kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}










int main()
{
    cout<<"@@@@@@@@@@@@@@"<<endl<<"SPACE INVADERS"<<endl<<"@@@@@@@@@@@@@@"<<endl;
    cout<<"Sterowanie: A,D ruchy w prawo i lewo; spacja strzal"<<endl;
    getch();



    Position::indxx=0;

    PlayerShip shipp;
    AlienPack AP;
    BulletPack BP;
    GameMap gamemapp(20,50);
    gamemapp.initialUpdate();
    std::srand( time( NULL ) );
    int itr=0;


    while(!shipp.dead())
    {
        int rand_number=(std::rand() % (gamemapp.getWidth()-3)  + 2);
        itr=itr+1;

        usleep(30000);

        int t=50;
        int sp=1;
        int sd=50;

        gamemapp.getLifePlayer(shipp);
        gamemapp.update(shipp);
        gamemapp.display();
        AP.AddTimeDepend(itr, rand_number);
        AP.moveAlienShips(gamemapp,t,sp,itr);
        AP.EraseAlienShip(BP,sd, itr,gamemapp);
        BP.Compare(shipp,gamemapp);
        BP.moveBullets(gamemapp,itr);


        if(kbhit())
        {
            int ch = getch();
            switch(ch)
            {

            case 32:
                //BP.IsShooting(shipp, ch) <PlayerShip,'|',true> ;
                BP.IsShooting(shipp, ch);
                break;
            case 97:
                shipp.moveShip(ch);
                break;

            case 100:
                shipp.moveShip(ch);
                break;

            default:
                break;

            }
        }




    };

    system("clear");
    cout<<"GAME OVER"<<endl;
    AP.~AlienPack();
    BP.~BulletPack();
    shipp.~PlayerShip();
    gamemapp.~GameMap();


    getchar();
    return 0;





}



