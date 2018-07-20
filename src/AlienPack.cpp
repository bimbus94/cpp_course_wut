#include "AlienPack.hpp"

bool AlienToDelete(AlienShip bul)
{
    if(bul.getErasedIndx()!=-1)
    {
        return true;
    }
    return false;
}




AlienPack::AlienPack()
{
    vector<AlienShip> storageAlien;
};

AlienPack::~AlienPack()
{};


void AlienPack::Add(AlienShip& bul)
{
    storageAlien.push_back(bul);
};

void AlienPack::AddTimeDepend(int& itr, int& rand_number)
{

    if(itr%101==0)
    {
        storageAlien.push_back(AlienShip(rand_number,4,1,1,'V',1,1,1));
    };

}





void AlienPack::moveAlienShips(GameMap& gm ,int& s_p, int& s,int& itr)
{
    if(itr%22==0)
    {

        for (vector<AlienShip>::iterator it = AlienPack::storageAlien.begin() ; it != AlienPack::storageAlien.end(); ++it)
        {
            it->moveShip(s_p);


            it->moveShipVertical(s);

            gm.update(*it);

        };
    };

}

void AlienPack::EraseAlienShip(BulletPack& BP, int& s_d, int& itr, GameMap& gm)
{
    if(storageAlien.size()>0)
    {
        for (vector<AlienShip>::iterator it = AlienPack::storageAlien.begin() ; it != AlienPack::storageAlien.end(); ++it)
        {
            if(itr%44==0)
            {
                BP.AlienIsShooting(*it, s_d);
            }
            BP.CompareA(*it,gm);

        };
    };
    storageAlien.erase(std::remove_if(storageAlien.begin(), storageAlien.end(), AlienToDelete), storageAlien.end());
};





