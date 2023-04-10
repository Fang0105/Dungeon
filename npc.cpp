#include<iostream>
#include"npc.h"
using namespace std;

NPC::NPC(string script,vector<Weapon>commodity,string name, int maxHealth, int currentHealth, int attack, int defense):GameCharacter(name,maxHealth,currentHealth,attack,defense){
    this->script = script;
    this->commodity = commodity;
}
// TODO
// void NPC::showCommodity(){
    
// }

// bool NPC::buyWeapon(Weapon){
   
// }

void NPC::setScript(string script){
    this->script = script;
}

void NPC::setCommodity(vector<Weapon>commodity){
    this->commodity = commodity;
}

string NPC::getScript(){
    return this->script;
}

vector<Weapon> NPC::getCommodity(){
    return this->commodity;
}