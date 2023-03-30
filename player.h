#ifndef __PLAYER_H
#define __PLAYER_H

#include"gameCharacter.h"
#include"room.h"

class Room;

class Player: private GameCharacter{
    private:
        int weapons;
        int money;
        int level;
        Room *currentRoom;
    public:
        Player();
        Player(int, int, int);
        void getNewWeapon(Weapon);
        virtual void showStatus()=0;
        virtual void attack(::GameCharacter*)=0;
        virtual void hurt()=0;
};


class Tank: private Player{
    private:
        int perfectDefensePromity;
    public:
        virtual void attack(::GameCharacter*);
        virtual void hurt();
        virtual void showStatus();
        void setPerfectDefensePromity(int);
        int getPerfectDefensePromity();
};

class Fighter: private Player{
    private:
        int hardStrikePromity;
    public:
        virtual void attack(::GameCharacter*);
        virtual void hurt();
        virtual void showStatus();
        void setHardStrikePromity(int);
        int getHardStrikePromity();
};

class Magician: private Player{
    private:
        int perfectHealPromity;
    public:
        virtual void attack(::GameCharacter*);
        virtual void hurt();
        virtual void showStatus();
        void setPerfectHealthPromity(int);
        int getPerfectHealthPromity();
};

#endif