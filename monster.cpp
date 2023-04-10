#include<iostream>
#include"monster.h"
using namespace std;

Monster::Monster(int dropExp,int dropMoney,string name, int maxHealth, int currentHealth, int attack, int defense):GameCharacter(name,maxHealth,currentHealth,attack,defense){
    this->dropExp = dropExp;
    this->dropMoney = dropMoney;
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