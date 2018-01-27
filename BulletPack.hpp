#ifndef BULLETPACK_H
#define BULLETPACK_H
#include "PlayerShip.hpp"
#include <vector>
#include "GameMap.hpp"
#include "AlienShip.hpp"
#include <algorithm>
#include <memory>
#include <iterator>



class BulletPack
    : public Bullet

{

private:
    vector<Bullet> storage;

public:

    BulletPack();

    ~BulletPack();


    void Add(Bullet&);

    void Compare(PlayerShip&, GameMap&);
    void CompareA(AlienShip&, GameMap&);

    //template<typename T, char C, bool B>
    void IsShooting(PlayerShip&, int&);

    void AlienIsShooting(AlienShip&, int&);

    void moveBullets(GameMap&,int&);

    bool IsBulletToDelete(const Bullet* bul);
};


#endif

