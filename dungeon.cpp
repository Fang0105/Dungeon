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
    Room *initialRoom;

    NPCRoom *npcRoom_1;
    NPC *npc_1;

    MonsterRoom *monsterRoom_1, *monsterRoom_2, *monsterRoom_3;
    Monster *monster_1, *monster_2, *monster_3;

    TreasureRoom *treasureRoom_1,*treasureRoom_2;
    Weapon weapon_1, weapon_2;
    int money_1=10,money_2=10; //TODO: decide money

    initialRoom = new Room(npcRoom_1,nullptr,nullptr,nullptr);
    npcRoom_1 = new NPCRoom(npc_1,treasureRoom_1,initialRoom,monsterRoom_1,monsterRoom_2);
    monsterRoom_1 = new MonsterRoom(monster_1,monsterRoom_3,nullptr,nullptr,nullptr);
    monsterRoom_2 = new MonsterRoom(monster_2,treasureRoom_2,nullptr,npcRoom_1,nullptr);
    monsterRoom_3 = new MonsterRoom(monster_3,nullptr,monsterRoom_1,nullptr,nullptr);
    treasureRoom_1 = new TreasureRoom(weapon_1,money_1,nullptr,npcRoom_1,nullptr,nullptr);
    treasureRoom_2 = new TreasureRoom(weapon_2,money_2,nullptr,monsterRoom_2,nullptr,nullptr);

    return initialRoom;
}

Player* Dungeon::createPlayer(){
    string occupation;
    //------------------------GameCharacter------------------------
    string name;
    int maxHealth = 100;
    int currentHealth = 100;
    int attack = 15;
    int defense = 5;
    //-------------------------------------------------------------

    //------------------------Player-------------------------------
    vector<Weapon> weapons;
    int money = 0;
    int level = 1;
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
            player = new Tank(perfectDefensePromity,weapons,money,level,exp,name,maxHealth,currentHealth,attack,defense);
            break;
        }else if(occupation=="B"){
            cout<<"Your name:"<<endl<<"=>";
            cin.ignore();
            getline(cin,name);
            int hardStrikePromity = 0;
            player = new Fighter(hardStrikePromity,weapons,money,level,exp,name,maxHealth,currentHealth,attack,defense);
            break;
        }else if(occupation=="C"){
            cout<<"Your name:"<<endl<<"=>";
            cin.ignore();
            getline(cin,name);
            int perfectHealPromity = 0;
            player = new Magician(perfectHealPromity,weapons,money,level,exp,name,maxHealth,currentHealth,attack,defense);
            break;
        }else{
            cout<<occupation<<" is not an occupation choice !!!"<<endl;
        }
    }while(true);
    


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

void Dungeon::runGame(){
    bool wantNextAction = true;
    string action;
    while(checkGameLogic() && wantNextAction){
        do{
            cout<<"Choose next Action: (A)exit the game (B)move to another room (C)show status"<<endl;
            cin>>action;
            if(action=="A"){
                wantNextAction = false;
                break;
            }else if(action=="B"){
                //TODO : move to another room
                break;
            }else if(action=="C"){
                getPlayer()->showStatus();
                break;
            }else{
                cout<<action<<" is not an action choice !!!"<<endl;
            }
        }while(true);
        

        
    }
}