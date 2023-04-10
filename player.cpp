#include<iostream>
#include"player.h"
using namespace std;


Player::Player(){}

Player::Player(vector<Weapon>weapons, int money, int level,int exp,string name, int maxHealth, int currentHealth, int attack, int defense):GameCharacter(name,maxHealth,currentHealth,attack,defense){
    this->weapons = weapons;
    this->money = money;
    this->level = level;
    this->exp = exp;
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

void Player::setExp(int exp){
    this->exp = exp;
}

void Player::setTag(string tag){
    this->tag = tag;
}

void Player::setCurrentRoom(Room* currentrRoom){
    this->currentRoom = currentrRoom;
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

int Player::getExp(){
    return this->exp;
}

string Player::getTag(){
    return this->tag;
}

Room* Player::getCurrentRoom(){
    return this->currentRoom;
}

Tank::Tank(){
    cout<<"You are a Tank now!"<<endl;
    this->tag = "Tank";
}

Tank::Tank(int perfectDefensePromityvector, vector<Weapon>weapons, int money, int level,int exp, string name, int maxHealth, int currentHealth, int attack, int defense):Player(weapons, money, level, exp, name, maxHealth, currentHealth, attack, defense){
    this->perfectDefensePromity = perfectDefensePromity;
    this->tag = "Tank";
    cout<<"You are a Tank now!"<<endl;
}

void Tank::setPerfectDefensePromity(int perfectDefensePromity){
    this->perfectDefensePromity = perfectDefensePromity;
}

int Tank::getPerfectDefensePromity(){
    return this->perfectDefensePromity;
}

Fighter::Fighter(){
    cout<<"You are a Fighter now!"<<endl;
    this->tag = "Fighter";
}

Fighter::Fighter(int hardStrikePromity, vector<Weapon>weapons, int money, int level,int exp, string name, int maxHealth, int currentHealth, int attack, int defense):Player(weapons, money, level, exp, name, maxHealth, currentHealth, attack, defense){
    this->hardStrikePromity = hardStrikePromity;
    this->tag = "Fighter";
    cout<<"You are a Fighter now!"<<endl;
}

void Fighter::setHardStrikePromity(int hardStrikePromity){
    this->hardStrikePromity = hardStrikePromity;
}

int Fighter::getHardStrikePromity(){
    return this->hardStrikePromity;
}

Magician::Magician(){
    cout<<"You are a Magician now!"<<endl;
    this->tag = "Magician";
}

Magician::Magician(int perfectHealPromity, vector<Weapon>weapons, int money, int level, int exp, string name, int maxHealth, int currentHealth, int attack, int defense):Player(weapons, money, level, exp, name, maxHealth, currentHealth, attack, defense){
    this->perfectHealPromity = perfectHealPromity;
    this->tag = "Magician";
    cout<<"You are a Magician now!"<<endl;
}

void Magician::setPerfectHealthPromity(int perfectHealPromity){
    this->perfectHealPromity = perfectHealPromity;
}

int Magician::getPerfectHealthPromity(){
    return this->perfectHealPromity;
}

//TODO : virtual function implementation

//Tank
void Tank::showStatus(){
    cout<<"Name : "<<getName()<<endl;
    cout<<"Occupation : "<<getTag()<<endl;
    cout<<"Health : "<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
    cout<<"Attack : "<<getAttack()<<endl;
    cout<<"Defense : "<<getDefense()<<endl;
    cout<<"Money : "<<getMoney()<<endl;
    cout<<"Level : "<<getLevel()<<endl;
    cout<<"EXP : "<<getExp()<<endl;
    cout<<"Weapons : ";
    vector<Weapon>w = getWeapon();
    if(w.size()==0){
       cout<<" no weapon"<<endl;
    }else{
        for(int i=0;i<w.size();i++){
            if(i!=0){
                cout<<"         ";
            }
            cout<<w[i]<<endl;
        }
    }
    cout<<"PerfectDefensePromity : "<<getPerfectDefensePromity()<<endl;
}
void Tank::attack(::GameCharacter*){}
void Tank::hurt(){}

//Fighter
void Fighter::showStatus(){
    cout<<"Name : "<<getName()<<endl;
    cout<<"Occupation : "<<getTag()<<endl;
    cout<<"Health : "<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
    cout<<"Attack : "<<getAttack()<<endl;
    cout<<"Defense : "<<getDefense()<<endl;
    cout<<"Money : "<<getMoney()<<endl;
    cout<<"Level : "<<getLevel()<<endl;
    cout<<"EXP : "<<getExp()<<endl;
    cout<<"Weapons : ";
    vector<Weapon>w = getWeapon();
    if(w.size()==0){
       cout<<" no weapon"<<endl;
    }else{
        for(int i=0;i<w.size();i++){
            if(i!=0){
                cout<<"         ";
            }
            cout<<w[i]<<endl;
        }
    }
    cout<<"HardStrikePromity : "<<getHardStrikePromity()<<endl;
}
void Fighter::attack(::GameCharacter*){}
void Fighter::hurt(){}

//Magician
void Magician::showStatus(){
    cout<<"Name : "<<getName()<<endl;
    cout<<"Occupation : "<<getTag()<<endl;
    cout<<"Health : "<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
    cout<<"Attack : "<<getAttack()<<endl;
    cout<<"Defense : "<<getDefense()<<endl;
    cout<<"Money : "<<getMoney()<<endl;
    cout<<"Level : "<<getLevel()<<endl;
    cout<<"EXP : "<<getExp()<<endl;
    cout<<"Weapons : ";
    vector<Weapon>w = getWeapon();
    if(w.size()==0){
       cout<<" no weapon"<<endl;
    }else{
        for(int i=0;i<w.size();i++){
            if(i!=0){
                cout<<"         ";
            }
            cout<<w[i]<<endl;
        }
    }
    cout<<"perfectHealPromity : "<<getPerfectHealthPromity()<<endl;
}
void Magician::attack(::GameCharacter*){}
void Magician::hurt(){}