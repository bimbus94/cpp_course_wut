#include "BulletPack.hpp"
bool BulletToDelete(Bullet bul)
{
    if(bul.getErasedIndx()!=-1)
    {
        return true;
    }
    return false;
}

BulletPack::BulletPack()
{
    vector<Bullet*> storage;
};

BulletPack::~BulletPack()
{};

void BulletPack::Add(Bullet& bul)
{
    storage.push_back(bul);
};

void BulletPack::Compare(PlayerShip& ship, GameMap& gm)
{
    for (std::vector<Bullet>::iterator it = BulletPack::storage.begin() ; it != BulletPack::storage.end(); ++it)
    {

        if((*it)==ship && !(it->getDir())) //co sie dzieje jak pocisk spotka sie ze statkiem
        {
            ship.getHurt(); //trafienie statku
            it->eraseIndx();
            gm.update(*it);
            it->zeroIndx();

        }

        else if ((it->getPositionY())<2 ||(it->getPositionY())>18) // PRZEKROCZENIE KOŃCA MAPY TEZ USUNIECIE POCISKU
        {
            it->eraseIndx();
            gm.update(*it);
            it->zeroIndx();

        }



    };

    storage.erase(std::remove_if(storage.begin(), storage.end(), BulletToDelete), storage.end());
};


void BulletPack::CompareA(AlienShip& sh, GameMap& gm)
{
    if(storage.size()>0)
    {
        for (vector<Bullet>::iterator it = BulletPack::storage.begin() ; it != BulletPack::storage.end(); ++it)
        {

            if((*it)==sh && (it->getDir()) )//co sie dzieje jak pocisk spotka sie ze statkiem
            {

                sh.getHurt();

                sh.eraseIndx();

                it->eraseIndx();
                gm.update(*it);
                it->zeroIndx();
                gm.update(sh);

                sh.zeroIndx();


            }

            if ((it->getPositionY())<2 ||(it->getPositionY())>19) // PRZEKROCZENIE KOŃCA MAPY TEZ USUNIECIE POCISKU
            {

                it->eraseIndx();
                gm.update(*it);
                it->zeroIndx();
            }



            if ((sh.getPositionY())<2 ||(sh.getPositionY())>18||(sh.getPositionX())<2 ||(sh.getPositionY())>48) // PRZEKROCZENIE KOŃCA MAPY TEZ USUNIECIE POCISKU
            {

                sh.eraseIndx();
                gm.update(sh);
                sh.zeroIndx();
            }



        };
    };
    storage.erase(std::remove_if(storage.begin(), storage.end(), BulletToDelete), storage.end());

};

/*template<typename T, char C, bool B>
void BulletPack::IsShooting(T& ship, int& KeyBoardPress)
{
    if(ship.shoot(KeyBoardPress))
    {
        storage.push_back(Bullet(ship.getPositionX(),ship.getPositionY(),1,1,C, B));
    };
}*/

void BulletPack::IsShooting(PlayerShip& ship, int& KeyBoardPress)
{
    if(ship.shoot(KeyBoardPress))
    {
        storage.push_back(Bullet(ship.getPositionX(),ship.getPositionY(),1,1,'|', true));
    };
}
void BulletPack::AlienIsShooting(AlienShip& alien, int& s_p)
{
    if(alien.shoot(s_p))
    {
        storage.push_back(Bullet(alien.getPositionX(),alien.getPositionY(),1,1,'*', false));
    };
}



void BulletPack::moveBullets(GameMap& gm, int& itr)
{
    if(itr%1==0)
    {
        for (vector<Bullet>::iterator it = BulletPack::storage.begin() ; it != BulletPack::storage.end(); ++it)
        {
            it->moveBullet();
            gm.update(*it);

        };
    };
};




