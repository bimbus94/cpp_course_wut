#ifndef AlienPack_H
#define AlienPack_H
#include "PlayerShip.hpp"

#include "GameMap.hpp"
#include "AlienShip.hpp"
#include "BulletPack.hpp"
#include <vector>



class AlienPack
    : public AlienShip

{

private:
    vector<AlienShip> storageAlien;

public:

    AlienPack();

    ~AlienPack();


    void Add(AlienShip&);
    void AddTimeDepend(int&, int&);
    void moveAlienShips(GameMap&, int&, int&,int&);
    void EraseAlienShip(BulletPack&, int&, int&, GameMap&);


};
#endif

