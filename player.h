#ifndef __PLAYER_H
#define __PLAYER_H

#include"gameCharacter.h"
#include"room.h"
#include"weapon.h"
#include"monster.h"
#include<vector>

class Room;
class Monster;

class Player: public GameCharacter{
    public:
        string tag;
        vector<Weapon> weapons;
        int money;
        int level;
        int exp;
        Room *currentRoom;

        Player();
        Player(vector<Weapon>, int, int, int, string, int, int, int, int);
        void setWeapons(vector<Weapon>);
        void setMoney(int);
        void setLevel(int);
        void setExp(int);
        void setTag(string);
        void setCurrentRoom(Room*);
        vector<Weapon> getWeapons();
        int getMoney();
        int getLevel();
        int getExp();
        string getTag();
        Room* getCurrentRoom();
        void getNewWeapon(Weapon);
        void heal();
        virtual void showStatus()=0;
        virtual void attackMonster(Monster*, Weapon*)=0;
        virtual void hurt(int)=0;
        void levelUp();
        Weapon* chooseWeapon();
        void deleteBrokenWeapons();
};


class Tank: public Player{
    public:
        
        int perfectDefensePromity;

        Tank();
        Tank(int,vector<Weapon>, int, int, int, string, int, int, int, int);
        virtual void attackMonster(Monster*, Weapon*);
        virtual void hurt(int);
        virtual void showStatus();
        void setPerfectDefensePromity(int);
        int getPerfectDefensePromity();
};

class Fighter: public Player{
    public:
        int hardStrikePromity;

        Fighter();
        Fighter(int,vector<Weapon>, int, int, int, string, int, int, int, int);
        virtual void attackMonster(Monster*, Weapon*);
        virtual void hurt(int);
        virtual void showStatus();
        void setHardStrikePromity(int);
        int getHardStrikePromity();
};

class Magician: public Player{
    public:
        int perfectHealPromity;

        Magician();
        Magician(int,vector<Weapon>, int, int, int, string, int, int, int, int);
        virtual void attackMonster(Monster*, Weapon*);
        virtual void hurt(int);
        virtual void showStatus();
        void setPerfectHealthPromity(int);
        int getPerfectHealthPromity();
};

#endif