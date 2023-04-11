#ifndef __DUNGEON_H
#define __DUNGEON_H

#include"player.h"
#include"room.h"

class Dungeon{
    public:
        Player *player;
        Room *initialRoom;

        Dungeon();
        Dungeon(Player*, Room*);
        void startGame();
        void runGame();
        Room* createMap();
        Player* createPlayer();
        int checkGameLogic();
        void moveToAnotherRoom();
        void setPlayer(Player*);
        void setInitialRoom(Room*);
        Player* getPlayer();
        Room* getInitialRoom();
};

#endif