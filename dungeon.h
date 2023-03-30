#ifndef __DUNGEON_H
#define __DUNGEON_H

#include"player.h"
#include"room.h"

class Dungeon{
    private:
        Player *player;
        Room *initialRoom;
    public:
        Dungeon();
        Dungeon(Player*);
        void startGame();
        void runGame();
        Room* createMap();
        bool checkGameLogic();
        void chooseAction();
        void setPlayer(Player*);
        void setInitialRoom(Room*);
        Player* getPlayer();
        Room* getInitialRoom();
};

#endif