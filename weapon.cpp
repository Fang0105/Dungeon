#include<iostream>
#include"weapon.h"
using namespace std;

Weapon::Weapon(){}

Weapon::Weapon(string name, string occupation, int durability, int attack){
    this->name = name;
    this->occupation = occupation;
    this->durability = durability;
    this->attack = attack;
}

void Weapon::setName(string name){
    this->name = name;
}

void Weapon::setDurability(int durability){
    this->durability = durability;
}

void Weapon::setOccupation(string occupation){
    this->occupation = occupation;
}

void Weapon::setAttack(int attack){
    this->attack = attack;
}

int Weapon::getAttack(){
    return this->attack;
}

string Weapon::getName(){
    return this->name;
}

string Weapon::getOccupation(){
    return this->occupation;
}

int Weapon::getDurability(){
    return this->durability;
}

bool Weapon::isBroken(){
    if(getDurability()<=0){
        return true;
    }else{
        return false;
    }
}

void Weapon::wear(){
    if(getName()!="Bare Hand"){
        setDurability(getDurability()-1);
    }
}

ostream& operator<<(ostream &s, const Weapon &w){
    s<<"["<<" name: "<<w.name<<" , "<<"occupation: "<<w.occupation<<" , "<<"durability: "<<w.durability<<" ]";
    return s;
}