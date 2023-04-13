#ifndef __WEAPON_H
#define __WEAPON_H

#include<string>

using namespace std;

class Weapon{
    public:
        string name;
        string occupation;
        int durability;
        int attack;        
    
        Weapon();
        Weapon(string, string, int, int);
        void setName(string);
        void setOccupation(string);
        void setDurability(int);
        void setAttack(int);
        string getName();
        string getOccupation();
        int getDurability();
        int getAttack();
        bool isBroken();
        void wear();
};

ostream &operator<<(ostream&,const Weapon&);

#endif