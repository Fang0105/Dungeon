#ifndef __WEAPON_H
#define __WEAPON_H

#include<iostream>

using namespace std;

class Weapon{
    private:
        string name;
        int level;
        string occupation;
        int durability;        
    public:
        Weapon();
        Weapon(string, int, string, int);
        void consume();
        void setName(string);
        void setLevel(string);
        void setOccupation(string);
        void setDurability(int);
        string getName();
        int getLevel();
        string getOccupation();
        int getDurability();
};

#endif