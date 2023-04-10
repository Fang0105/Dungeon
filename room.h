#ifndef __ROOM_H
#define __ROOM_H

#include"weapon.h"
#include"monster.h"
#include"npc.h"
#include"player.h"

class Player;

class Room{
    public:
        Room *upRoom;
        Room *downRoom;
        Room *leftRoom;
        Room *rightRoom;
        string tag;

        Room();
        Room(Room*,Room*,Room*,Room*);
        void setUpRoom(Room*);
        void setDownRoom(Room*);
        void setLeftRoom(Room*);
        void setRightRoom(Room*);
        void setTag(string);
        Room* getUpRoom();
        Room* getDownRoom();
        Room* getLeftRoom();
        Room* getRightRoom();
        string getTag();
};

class TreasureRoom: public Room{
    public:
        Weapon dropWeapon;
        int dropMoney;

        TreasureRoom();
        TreasureRoom(Weapon,int,Room*,Room*,Room*,Room*);
        void getTresure(Player*);
        void setDropWeapon(Weapon);
        void setDropMoney(int);
        Weapon getDropWeapon();
        int getDropMoney();
};

class MonsterRoom: public Room{
    public:
        Monster *monster;

        MonsterRoom();
        MonsterRoom(Monster*,Room*,Room*,Room*,Room*);
        void setMonster(Monster*);
        Monster* getMonster();
};

class NPCRoom: public Room{
    public:
        NPC *npc;

        NPCRoom();
        NPCRoom(NPC*,Room*,Room*,Room*,Room*);
        void setNPC(NPC*);
        NPC* getNPC();
};

#endif