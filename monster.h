#ifndef __MONSTER_H
#define __MONSTER_H

#include"gameCharacter.h"

class Monster: public GameCharacter{
    public:
        int dropExp;
        int dropMoney;

        Monster();
        Monster(int, int, string, int, int, int, int);
        void setDropExp(int);
        void setDropMoney(int);
        int getDropExp();
        int getDropMoney();
};

#endif