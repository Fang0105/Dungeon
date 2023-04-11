#include<iostream>
#include<cstdlib>
#include<ctime>
#include"player.h"
using namespace std;

int getRandomNumer1(int a,int b){
    return (rand()%(b-a+1)+a);
}

Player::Player(){}

Player::Player(vector<Weapon>weapons, int money, int level,int exp,string name, int maxHealth, int currentHealth, int attack, int defense):GameCharacter(name,maxHealth,currentHealth,attack,defense){
    this->weapons = weapons;
    this->money = money;
    this->level = level;
    this->exp = exp;
}

void Player::setWeapons(vector<Weapon>weapons){
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

vector<Weapon> Player::getWeapons(){
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

void Player::levelUp(){
    if(getLevel()==20){
        return;
    }
    while( getLevel()<20 && getExp()>=100 ){
        cout<<"Level up : "<<getLevel();
        setMaxHealth(getMaxHealth()+100);
        setCurrentHealth(getMaxHealth());
        setAttack(getAttack()+3);
        setDefense(getDefense()+1);
        setLevel(getLevel()+1);
        setExp(getExp()-100);
        cout<<" -> "<<getLevel()<<endl;
    }
}

string Player::getTag(){
    return this->tag;
}

Room* Player::getCurrentRoom(){
    return this->currentRoom;
}

void Player::heal(){
    setCurrentHealth(getMaxHealth());
}

Weapon* Player::chooseWeapon(){
    if(this->weapons.size()==0){
       cout<<" no weapon"<<endl;
    }else{
        int idx;
        do{
            cout<<"Choose one weapon :"<<endl;
            for(int i=0;i<this->weapons.size();i++){
                cout<<"("<<i+1<<") "<<this->weapons[i]<<endl;
            }
            cout<<"=>";
            cin>>idx;
            if( idx>0 && idx<=this->weapons.size() ){
                return &this->weapons[idx-1];
            }else{
                cout<<idx<<" is not a choice"<<endl;
            }
        }while(true);
    }

}

void Player::deleteBrokenWeapons(){
    vector<Weapon>afterDelete;
    vector<Weapon>beforeDelete = getWeapons();
    for(int i=0;i<beforeDelete.size();i++){
        if(beforeDelete[i].getDurability()>0){
            afterDelete.push_back(beforeDelete[i]);
        }
    }
    setWeapons(afterDelete);
}

void Player::getNewWeapon(Weapon weapon){
    this->weapons.push_back(weapon);
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
    this->perfectDefensePromity = getLevel()*2;
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
    this->hardStrikePromity = getLevel();
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
    this->perfectHealPromity = getLevel()/2;
    return this->perfectHealPromity;
}

//TODO : virtual function implementation

//Tank
void Tank::showStatus(){
    cout<<"-Name : "<<getName()<<endl;
    cout<<"-Occupation : "<<getTag()<<endl;
    cout<<"-Health : "<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
    cout<<"-Attack : "<<getAttack()<<endl;
    cout<<"-Defense : "<<getDefense()<<endl;
    cout<<"-Money : "<<getMoney()<<endl;
    cout<<"-Level : "<<getLevel()<<endl;
    cout<<"-EXP : "<<getExp()<<endl;
    cout<<"-Weapons : ";
    vector<Weapon>w = getWeapons();
    if(w.size()==0){
       cout<<" no weapon"<<endl;
    }else{
        for(int i=0;i<w.size();i++){
            if(i!=0){
                cout<<"           ";
            }
            cout<<w[i]<<endl;
        }
    }
    cout<<"-PerfectDefensePromity : "<<getPerfectDefensePromity()<<endl;
}
void Tank::attackMonster(Monster* monster, Weapon* weapon){
    int totalAttack = getAttack()+weapon->getAttack();
    if(weapon->getOccupation()=="Tank"){
        totalAttack*=1.5;
    }
    monster->hurt(totalAttack);
}
void Tank::hurt(int totalAttack){
    srand(time(NULL));
    int pp = getRandomNumer1(1,100);
    if(pp<=getPerfectDefensePromity()){
        cout<<"Perfect Defense !!!"<<endl;
    }else{
        setCurrentHealth(getCurrentHealth()-max(0,totalAttack-getDefense()));
    }
}

//Fighter
void Fighter::showStatus(){
    cout<<"-Name : "<<getName()<<endl;
    cout<<"-Occupation : "<<getTag()<<endl;
    cout<<"-Health : "<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
    cout<<"-Attack : "<<getAttack()<<endl;
    cout<<"-Defense : "<<getDefense()<<endl;
    cout<<"-Money : "<<getMoney()<<endl;
    cout<<"-Level : "<<getLevel()<<endl;
    cout<<"-EXP : "<<getExp()<<endl;
    cout<<"-Weapons : ";
    vector<Weapon>w = getWeapons();
    if(w.size()==0){
       cout<<" no weapon"<<endl;
    }else{
        for(int i=0;i<w.size();i++){
            if(i!=0){
                cout<<"           ";
            }
            cout<<w[i]<<endl;
        }
    }
    cout<<"-HardStrikePromity : "<<getHardStrikePromity()<<endl;
}
void Fighter::attackMonster(Monster* monster,Weapon* weapon){
    srand(time(NULL));
    int hp = getRandomNumer1(1,100);
    int totalAttack = getAttack()+weapon->getAttack();
    if(hp<=getHardStrikePromity()){
        cout<<"Hard Strike !!!"<<endl;
        totalAttack*=3;
    }
    if(weapon->getOccupation()=="Fighter"){
        totalAttack*=1.5;
    }
    monster->hurt(totalAttack);
}
void Fighter::hurt(int totalAttack){
    setCurrentHealth(getCurrentHealth()-max(0,totalAttack-getDefense()));
}

//Magician
void Magician::showStatus(){
    cout<<"-Name : "<<getName()<<endl;
    cout<<"-Occupation : "<<getTag()<<endl;
    cout<<"-Health : "<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
    cout<<"-Attack : "<<getAttack()<<endl;
    cout<<"-Defense : "<<getDefense()<<endl;
    cout<<"-Money : "<<getMoney()<<endl;
    cout<<"-Level : "<<getLevel()<<endl;
    cout<<"-EXP : "<<getExp()<<endl;
    cout<<"-Weapons : ";
    vector<Weapon>w = getWeapons();
    if(w.size()==0){
       cout<<" no weapon"<<endl;
    }else{
        for(int i=0;i<w.size();i++){
            if(i!=0){
                cout<<"           ";
            }
            cout<<w[i]<<endl;
        }
    }
    cout<<"-perfectHealPromity : "<<getPerfectHealthPromity()<<endl;
}
void Magician::attackMonster(Monster* monster,Weapon* weapon){
    int totalAttack = getAttack()+weapon->getAttack();
    if(weapon->getOccupation()=="Magician"){
        totalAttack*=1.5;
    }
    monster->hurt(totalAttack);
}
void Magician::hurt(int totalAttack){
    setCurrentHealth(getCurrentHealth()-max(0,totalAttack-getDefense()));
    srand(time(NULL));
    int pp = getRandomNumer1(1,100);
    if(pp<=getPerfectHealthPromity()){
        setCurrentHealth(getMaxHealth());
    }
}