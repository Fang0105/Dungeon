#ifndef __PLAYER_H
#define __PLAYER_H

#include"gameCharacter.h"
#include"room.h"
#include"weapon.h"
#include<vector>

class Room;

class Player: public GameCharacter{
    public:
        vector<Weapon> weapons;
        int money;
        int level;
        Room *currentRoom;

        Player();
        Player(vector<Weapon>, int, int, string, int, int, int, int);
        void setWeapon(vector<Weapon>);
        void setMoney(int);
        void setLevel(int);
        vector<Weapon> getWeapon();
        int getMoney();
        int getLevel();
        void getNewWeapon(Weapon);
        virtual void showStatus()=0;
        virtual void attack(::GameCharacter*)=0;
        virtual void hurt()=0;
};


class Tank: public Player{
    public:
        int perfectDefensePromity;

        virtual void attack(::GameCharacter*);
        virtual void hurt();
        virtual void showStatus();
        void setPerfectDefensePromity(int);
        int getPerfectDefensePromity();
};

class Fighter: public Player{
    public:
        int hardStrikePromity;

        virtual void attack(::GameCharacter*);
        virtual void hurt();
        virtual void showStatus();
        void setHardStrikePromity(int);
        int getHardStrikePromity();
};

class Magician: public Player{
    public:
        int perfectHealPromity;

        virtual void attack(::GameCharacter*);
        virtual void hurt();
        virtual void showStatus();
        void setPerfectHealthPromity(int);
        int getPerfectHealthPromity();
};

#endif