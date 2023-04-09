#include<iostream>
#include"gameCharacter.h"
using namespace std;

GameCharacter::GameCharacter(string name, int maxHealth, int currentHealth, int attack, int defense){
    this->name = name;
    this->maxHealth = maxHealth;
    this->currentHealth = currentHealth;
    this->attack = attack;
    this->defense = defense;
}

bool GameCharacter::checkIsDead(){
    if( this->currentHealth < 0 ){
        return true;
    }else{
        return false;
    }
}

void GameCharacter::setName(string name){
    this->name = name;
}

void GameCharacter::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}

void GameCharacter::setCurrentHealth(int currentHealth){
    this->currentHealth = currentHealth;
}

void GameCharacter::setAttack(int attack){
    this->attack = attack;
}

void GameCharacter::setDefense(int defense){
    this->defense = defense;
}

string GameCharacter::getName(){
    return this->name;
}

int GameCharacter::getMaxHealth(){
    return this->maxHealth;
}

int GameCharacter::getCurrentHealth(){
    return this->currentHealth;
}

int  GameCharacter::getAttack(){
    return this->attack;
}

int GameCharacter::getDefense(){
    return this->defense;
}
