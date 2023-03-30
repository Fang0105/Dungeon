#ifndef __MONSTER_H
#define __MONSTER_H

#include"gameCharacter.h"

class Monster: private GameCharacter{
    private:
        int dropExp;
        int dropMoney;
    public:
        Monster();
        void setDropExp(int);
        void setDropMoney(int);
        int getDropExp(int);
        int getDropMoney(int);
};

#endif