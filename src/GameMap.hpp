#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "Position.hpp"
#include <unistd.h>
#include <vector>
#include <algorithm>
#include "PlayerShip.hpp"
class GameMap

{
private:
    int height, width;

    // std::vector< std::vector<char> > vec;
    std::vector< std::vector<char> > vec;
    std::vector< std::vector<int> > vec2;
    int lifePlayer;

public:

    GameMap();

    GameMap(const int&, const int&);

    ~GameMap();

    void initialUpdate();
    void update(Position&);
    void display();
    void getLifePlayer(PlayerShip& );
    int getHeight();
    int getWidth();



};


#endif
