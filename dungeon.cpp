#include<iostream>
#include"dungeon.h"
#include"monster.h"
#include"npc.h"
#include"player.h"
using namespace std;

Dungeon::Dungeon(){}

Dungeon::Dungeon(Player* player,Room* initialRoom){
    this->player = player;
    this->initialRoom = initialRoom;
}

void Dungeon::setPlayer(Player* player){
    this->player = player;
}

void Dungeon::setInitialRoom(Room* initialRoom){
    this->initialRoom = initialRoom;
}

Player* Dungeon::getPlayer(){
    return this->player;
}

Room* Dungeon::getInitialRoom(){
    return this->initialRoom;
}

Room* Dungeon::createMap(){
    Room *initialRoom = new Room;

    NPCRoom *npcRoom_1 = new NPCRoom;
    NPC *npc_1;

    MonsterRoom *monsterRoom_1 = new MonsterRoom, *monsterRoom_2 = new MonsterRoom, *monsterRoom_3 = new MonsterRoom;
    Monster *monster_1 = new Monster, *monster_2 = new Monster, *monster_3 = new Monster;

    TreasureRoom *treasureRoom_1 = new TreasureRoom(),*treasureRoom_2 = new TreasureRoom();
    Weapon weapon_1, weapon_2;
    int money_1=10,money_2=10; //TODO: decide money

    initialRoom->setFourRoom(npcRoom_1,nullptr,nullptr,nullptr);
    npcRoom_1->setFourRoom(treasureRoom_1,initialRoom,monsterRoom_1,monsterRoom_2);
    monsterRoom_1->setFourRoom(monsterRoom_3,nullptr,nullptr,nullptr);
    monsterRoom_2->setFourRoom(treasureRoom_2,nullptr,npcRoom_1,nullptr);
    monsterRoom_3->setFourRoom(nullptr,monsterRoom_1,nullptr,nullptr);
    treasureRoom_1->setFourRoom(nullptr,npcRoom_1,nullptr,nullptr);
    treasureRoom_2->setFourRoom(nullptr,monsterRoom_2,nullptr,nullptr);

    monsterRoom_1->setMonster(monster_1);
    monsterRoom_2->setMonster(monster_2);
    monsterRoom_3->setMonster(monster_3);
    
    return initialRoom;
}

Player* Dungeon::createPlayer(){
    string occupation;
    //------------------------GameCharacter------------------------
    string name;
    int maxHealth = 1000;
    int currentHealth = 1000;
    int attack = 100;
    int defense = 25;
    //-------------------------------------------------------------

    //------------------------Player-------------------------------
    vector<Weapon> weapons;
    Weapon w = Weapon("Bare Hand","all",100);
    weapons.push_back(w);
    int money = 0;
    int level = 0;
    int exp = 0;
    Room *currentRoom = getInitialRoom();
    //-------------------------------------------------------------
    Player *player;
    do{
        cout<<"Choose one occupation: (A)Tank (B)Fighter (C)Magacian"<<endl<<"=>";
        cin>>occupation;
        
        if(occupation=="A"){
            cout<<"Your name:"<<endl<<"=>";
            cin.ignore();
            getline(cin,name);
            int perfectDefensePromity = 0;
            maxHealth = currentHealth = 2000;
            player = new Tank(perfectDefensePromity,weapons,money,level,exp,name,maxHealth,currentHealth,attack,defense);
            break;
        }else if(occupation=="B"){
            cout<<"Your name:"<<endl<<"=>";
            cin.ignore();
            getline(cin,name);
            int hardStrikePromity = 0;
            attack = 200;
            player = new Fighter(hardStrikePromity,weapons,money,level,exp,name,maxHealth,currentHealth,attack,defense);
            break;
        }else if(occupation=="C"){
            cout<<"Your name:"<<endl<<"=>";
            cin.ignore();
            getline(cin,name);
            int perfectHealPromity = 0;
            defense = 50;
            player = new Magician(perfectHealPromity,weapons,money,level,exp,name,maxHealth,currentHealth,attack,defense);
            break;
        }else{
            cout<<occupation<<" is not an occupation choice !!!"<<endl;
        }
    }while(true);
    player->setCurrentRoom(currentRoom);

    return player;
}

void Dungeon::startGame(){
    setInitialRoom(createMap());
    setPlayer(createPlayer());
}

bool Dungeon::checkGameLogic(){
    if(getPlayer()->checkIsDead()){
        return false;
    }else{
        return true;
    }
}

void Dungeon::moveToAnotherRoom(){
    Room *currentRoom = getPlayer()->getCurrentRoom();
    do{
        cout<<"Choose one direction: (A)Up (B)Down (C)Left (D)Right"<<endl<<"=>";
        string direction;
        cin>>direction;
        if(direction=="A"){
            if(currentRoom->getUpRoom()==nullptr){
                cout<<"There is no room"<<endl;
            }else{
                getPlayer()->setCurrentRoom(currentRoom->getUpRoom());
                getPlayer()->currentRoom->roomEvent(getPlayer());
            }
            break;
        }else if(direction=="B"){
            if(currentRoom->getDownRoom()==nullptr){
                cout<<"There is no room"<<endl;
            }else{
                getPlayer()->setCurrentRoom(currentRoom->getDownRoom());
                getPlayer()->currentRoom->roomEvent(getPlayer());
            }
            break;
        }else if(direction=="C"){
            if(currentRoom->getLeftRoom()==nullptr){
                cout<<"There is no room"<<endl;
            }else{
                getPlayer()->setCurrentRoom(currentRoom->getLeftRoom());
                getPlayer()->currentRoom->roomEvent(getPlayer());
            }
            break;
        }else if(direction=="D"){
            if(currentRoom->getRightRoom()==nullptr){
                cout<<"There is no room"<<endl;
            }else{
                getPlayer()->setCurrentRoom(currentRoom->getRightRoom());
                getPlayer()->currentRoom->roomEvent(getPlayer());
            }
            break;
        }else{
            cout<<direction<<" is not an direction choice !!!"<<endl;
        }
    }while(true);
}

void Dungeon::runGame(){
    bool wantNextAction = true;
    string action;
    while(checkGameLogic() && wantNextAction){
        do{
            cout<<"Choose next Action: (A)exit the game (B)move to another room (C)stay in this room (D)show status"<<endl<<"=>";
            cin>>action;
            if(action=="A"){
                wantNextAction = false;
                break;
            }else if(action=="B"){
                moveToAnotherRoom();
                break;
            }else if(action=="C"){
                getPlayer()->getCurrentRoom()->roomEvent(getPlayer());
                break;
            }else if(action=="D"){
                getPlayer()->showStatus();
                break;
            }else{
                cout<<action<<" is not an action choice !!!"<<endl;
            }
        }while(true);
    }
    if(checkGameLogic()==false){
        cout<<"You lose ..."<<endl;
    }
    cout<<"End game, see you next time!"<<endl;
}

