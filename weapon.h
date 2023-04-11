#ifndef __WEAPON_H
#define __WEAPON_H

#include<string>

using namespace std;

class Weapon{
    public:
        string name;
        string occupation;
        int durability;        
    
        Weapon();
        Weapon(string, string, int);
        void consume();
        void setName(string);
        void setOccupation(string);
        void setDurability(int);
        string getName();
        string getOccupation();
        int getDurability();
        bool isBroken();
        void wear();
};

ostream &operator<<(ostream&,const Weapon&);

#endif