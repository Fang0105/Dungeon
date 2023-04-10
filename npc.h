#ifndef __NPC_H
#define __NPC_H

#include"gameCharacter.h"
#include"weapon.h"

class NPC: public GameCharacter{
    public:
        string script;
        vector<Weapon>commodity;

        NPC();
        NPC(string, vector<Weapon>, string, int, int, int, int);
        void showCommodity();
        bool buyWeapon(Weapon);
        void setScript(string);
        void setCommodity(vector<Weapon>);
        string getScript();
        vector<Weapon> getCommodity();
};

#endif