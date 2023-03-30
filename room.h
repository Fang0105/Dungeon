#ifndef __ROOM_H
#define __ROOM_H

#include"weapon.h"
#include"monster.h"
#include"npc.h"
#include"player.h"

class Player;

class Room{
    private:
        Room *upRoom;
        Room *downRoom;
        Room *leftRoom;
        Room *rightRoom;
    public:
        Room(Room*,Room*,Room,Room*);
        void setUpRoom(Room*);
        void setDownRoom(Room*);
        void setLeftRoom(Room*);
        void setRightRoom(Room*);
        Room* getUpRoom();
        Room* getDownRoom();
        Room* getLeftRoom();
        Room* getRightRoom();
};

class TreasureRoom: private Room{
    private:
        Weapon dropWeapon;
        int dropMoney;
    public:
        TreasureRoom();
        TreasureRoom(Weapon,int);
        void getTresure(Player*);
        void setDropWeapon(Weapon);
        void setDropMoney(int);
        Weapon getDropWeapon();
        int getDropMoney();
};

class MonsterRoom: private Room{
    private:
        Monster *monster;
    public:
        MonsterRoom();
        MonsterRoom(Monster*);
        void setMonster(Monster*);
        Monster* getMonster();
};

class NPCRoom: private Room{
    private:
        NPC *npc;
    public:
        NPCRoom();
        NPCRoom(NPC*);
        void setNPC(NPC*);
        NPC* getNPC();
};

#endif