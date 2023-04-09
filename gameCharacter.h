#ifndef __GAMECHARACTER_H
#define __GAMECHARACTER_H

#include<string>
#include<vector>
using namespace std;

class GameCharacter{
    private:
        string name;
        int maxHealth;
        int currentHealth;
        int attack;
        int defense;
    public:
        GameCharacter();
        GameCharacter(string, int, int, int, int);
        bool checkIsDead();
        void setName(string);
        void setMaxHealth(int);
        void setCurrentHealth(int);
        void setAttack(int);
        void setDefense(int);
        string getName();
        int getMaxHealth();
        int getCurrentHealth();
        int  getAttack();
        int getDefense();
};

#endif