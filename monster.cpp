#include<iostream>
#include"monster.h"
using namespace std;

int Monster::number = 0;
vector<string>monsterName = {"zombie","vampire","witch"};

Monster::Monster(){
    number++;
    this->dropExp = 10;
    this->dropMoney = 20;
    this->maxHealth = 500;
    this->currentHealth = 500;
    this->attack = 120;
    this->defense = 25;
    this->name = "zombie";
}

Monster::Monster(int dropExp,int dropMoney,string name, int maxHealth, int currentHealth, int attack, int defense):GameCharacter(name,maxHealth,currentHealth,attack,defense){
    this->dropExp = dropExp;
    this->dropMoney = dropMoney;
    number++;
}
void Monster::setDropExp(int dropExp){
    this->dropExp = dropExp;
}
void Monster::setDropMoney(int dropMoney){
    this->dropMoney = dropMoney;
}
int Monster::getDropExp(){
    return this->dropExp;
}
int Monster::getDropMoney(){
    return this->dropMoney;
}

void Monster::attackPlayer(Player *player){
    player->hurt(getAttack());
}

void Monster::heal(){
    setCurrentHealth(getMaxHealth());
}

void Monster::hurt(int totalAttack){
    setCurrentHealth(getCurrentHealth()-max(0,totalAttack-getDefense()));
}