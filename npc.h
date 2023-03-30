#ifndef __NPC_H
#define __NPC_H

#include"gameCharacter.h"
#include"weapon.h"

class NPC: private GameCharacter{
    private:
        string script;
        vector<Weapon>commodity;
    public:
        NPC();
        NPC(string,vector<Weapon>);
        void showCommodity();
        bool buyWeapon(Weapon);
        void setScript(string);
        void setCommodity(vector<Weapon>);
        string getScript();
        vector<Weapon> getCommodity();
};

#endif