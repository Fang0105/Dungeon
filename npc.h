#ifndef __NPC_H
#define __NPC_H

#include"gameCharacter.h"
#include"weapon.h"

class Commodity{
    public:
        int price;
        Weapon weapon;

        Commodity();
        Commodity(int,Weapon);
        void setPrice(int);
        void setWeapon(Weapon);
        int getPrice();
        Weapon getWeapon();
};

class NPC: public GameCharacter{
    public:
        string script;
        vector<Commodity>commodity;

        NPC();
        NPC(string, vector<Commodity>, string, int, int, int, int);
        void showCommodity();
        int buyCommodity(int);
        void setScript(string);
        void setCommodity(vector<Commodity>);
        string getScript();
        vector<Commodity> getCommodity();
};

extern vector<string>NPCname;
extern vector<string>script;

ostream &operator<<(ostream&,const Commodity&);

vector<Commodity> generateCommodities();

#endif