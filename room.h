#ifndef __ROOM_H
#define __ROOM_H

#include"weapon.h"
#include"monster.h"
#include"npc.h"
#include"player.h"

class Player;
class Monster;
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
        void setFourRoom(Room*, Room*, Room*, Room*);
        Room* getUpRoom();
        Room* getDownRoom();
        Room* getLeftRoom();
        Room* getRightRoom();
        string getTag();
        virtual void roomEvent(Player*);
};

class TreasureRoom: public Room{
    public:
        Weapon dropWeapon;
        int dropMoney;
        bool getTreasure;

        TreasureRoom();
        TreasureRoom(Weapon,int,Room*,Room*,Room*,Room*);
        void setDropWeapon(Weapon);
        void setDropMoney(int);
        Weapon getDropWeapon();
        int getDropMoney();
        virtual void roomEvent(Player*);
};

class MonsterRoom: public Room{
    public:
        Monster *monster;

        MonsterRoom();
        MonsterRoom(Monster*,Room*,Room*,Room*,Room*);
        void setMonster(Monster*);
        Monster* getMonster();
        virtual void roomEvent(Player*);
};

class NPCRoom: public Room{
    public:
        NPC *npc;

        NPCRoom();
        NPCRoom(NPC*,Room*,Room*,Room*,Room*);
        void setNPC(NPC*);
        NPC* getNPC();
        virtual void roomEvent(Player*);
};

#endif