#include<iostream>
#include"player.h"
using namespace std;

Player::Player(vector<Weapon>weapons, int money, int level,string name, int maxHealth, int currentHealth, int attack, int defense):GameCharacter(name,maxHealth,currentHealth,attack,defense){
    this->weapons = weapons;
    this->money = money;
    this->level = level;
}

void Player::setWeapon(vector<Weapon>weapons){
    this->weapons = weapons;
}

void Player::setMoney(int money){
    this->money = money;
}

void Player::setLevel(int level){
    this->level = level;
}

vector<Weapon> Player::getWeapon(){
    return this->weapons;
}

int Player::getMoney(){
    return this->money;
}

int Player::getLevel(){
    return this->level;
}

void Tank::setPerfectDefensePromity(int perfectDefensePromity){
    this->perfectDefensePromity = perfectDefensePromity;
}

int Tank::getPerfectDefensePromity(){
    return this->perfectDefensePromity;
}

void Fighter::setHardStrikePromity(int hardStrikePromity){
    this->hardStrikePromity = hardStrikePromity;
}

int Fighter::getHardStrikePromity(){
    return this->hardStrikePromity;
}

void Magician::setPerfectHealthPromity(int perfectHealPromity){
    this->perfectHealPromity = perfectHealPromity;
}
int Magician::getPerfectHealthPromity(){
    return this->perfectHealPromity;
}