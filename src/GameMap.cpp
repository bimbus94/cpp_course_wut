#include "GameMap.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;




GameMap::GameMap()
{}

GameMap::GameMap(const int& yy, const int& xx)
    :height(yy), width(xx)
{
    lifePlayer=0;
    //std::vector< std::vector<char> > vec(height, std::vector<char>(width));
    for ( int i = 0; i < height; i++ )
    {
        vec.push_back ( std::vector<char>() );
        vec2.push_back ( std::vector<int>() );
        for ( int j = 0; j < width; j++ )
        {
            vec[i].push_back ( i + j );
            vec2[i].push_back ( i + j );
        }
    }


}

GameMap::~GameMap()
{
    vec.clear();
    vec2.clear();

}

void GameMap::initialUpdate()
{

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if( i==0 ||  i==(height-1) || j==0 || j==(width-1))
            {
                vec[i][j]='!';
                vec2[i][j]=-1;
            }
            else
            {
                vec[i][j]=' ';
                vec2[i][j]=0;
            }
        }
        cout<<endl;
    }

}

void GameMap::update(Position &obj)
{


    for (std::vector< std::vector<int> >::iterator it = vec2.begin() ; it != vec2.end(); ++it)
    {

        std::vector<int>::iterator found;
        found = std::find((*it).begin(), (*it).end(), obj.getIndx());
        if ( found != it->end())
        {
            vec2[(it - vec2.begin())][(found - (*it).begin())]=0;
            vec[(it - vec2.begin())][(found - (*it).begin())]=' ';
            break;
        }
    }
    if(obj.getErasedIndx()==-1)
    {
        vec[obj.getPositionY()][obj.getPositionX()]=obj.getSymbol();
        vec2[obj.getPositionY()][obj.getPositionX()]=obj.getIndx();

    };

}


void GameMap::display()

{

    system("clear");

    for(int i=0; i<height; i++)
    {

        for(int j=0; j<width; j++)
        {
            cout<<vec[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Liczba zyc: "<<lifePlayer<<endl;
    //cout<<"Liczba punktow: "<<' '<<endl;
}

void GameMap::getLifePlayer(PlayerShip& ship)
{
    lifePlayer=ship.getLifeAmount();
}


int GameMap::getHeight()
{
    return height;
};

int GameMap::getWidth()
{
    return width;
};

