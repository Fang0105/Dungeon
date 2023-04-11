#ifndef __MONSTER_H
#define __MONSTER_H

#include"gameCharacter.h"
#include"player.h"

class Player;
class Monster: public GameCharacter{
    public:
        int dropExp;
        int dropMoney;
        static int number;

        Monster();
        Monster(int, int, string, int, int, int, int);
        void setDropExp(int);
        void setDropMoney(int);
        int getDropExp();
        int getDropMoney();
        void attackPlayer(Player*);
        void heal();
        void hurt(int);
};

extern vector<string>monsterName;

#endif