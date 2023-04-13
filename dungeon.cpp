#include<iostream>
#include<cstdlib>
#include<ctime>
#include"dungeon.h"
#include"monster.h"
#include"npc.h"
#include"player.h"
using namespace std;

int getRandomNumer2(int a,int b){
    return (rand()%(b-a+1)+a);
}

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
    vector<Commodity>commodity;
    Weapon spit = Weapon("spit","all",20,15);
    Commodity c1 = Commodity(0,spit);
    commodity.push_back(c1);
    srand(time(NULL));
    NPC *npc_1 = new NPC(script[getRandomNumer2(0,2)],commodity,NPCname[getRandomNumer2(0,3)],1,1,1,1);

    MonsterRoom *monsterRoom_1 = new MonsterRoom, *monsterRoom_2 = new MonsterRoom, *monsterRoom_3 = new MonsterRoom;
    Monster *monster_1 = new Monster, *monster_2 = new Monster, *monster_3 = new Monster;

    TreasureRoom *treasureRoom_1 = new TreasureRoom(),*treasureRoom_2 = new TreasureRoom();
    Weapon weapon_1, weapon_2;
    int money_1=10,money_2=10;
    if(getPlayer()->getTag()=="Tank"){
        weapon_1 = Weapon("helmet_1","Tank",50-13*1,15+10*1);
        weapon_2 = Weapon("chest_1","Tank",50-13*1,25+10*1);
        money_1 = 40;
        money_2 = 100;
    }else if(getPlayer()->getTag()=="Fighter"){
        weapon_1 = Weapon("sword_1","Fighter",50-13*1,15+10*1);
        weapon_2 = Weapon("arrow_1","Fighter",50-13*1,25+10*1);
        money_1 = 40;
        money_2 = 100;
    }else{
        weapon_1 = Weapon("flame_1","Magician",50-13*1,15+10*1);
        weapon_2 = Weapon("lightning_1","Magician",50-13*1,25+10*1);
        money_1 = 40;
        money_2 = 100;
    }

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
    
    npcRoom_1->setNPC(npc_1);

    treasureRoom_1->setDropMoney(money_1);
    treasureRoom_1->setDropWeapon(weapon_1);
    treasureRoom_2->setDropMoney(money_2);
    treasureRoom_2->setDropWeapon(weapon_2);

    return initialRoom;
}

Player* Dungeon::createPlayer(){
    string occupation;
    //------------------------GameCharacter------------------------
    string name;
    int maxHealth = 500;
    int currentHealth = 500;
    int attack = 100;
    int defense = 25;
    //-------------------------------------------------------------

    //------------------------Player-------------------------------
    vector<Weapon> weapons;
    Weapon w = Weapon("Bare Hand","all",100,10);
    weapons.push_back(w);
    int money = 200;
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
            maxHealth = currentHealth = 1000;
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

    return player;
}

void Dungeon::startGame(){
    setPlayer(createPlayer());
    Room* initialRoom = createMap();
    getPlayer()->setCurrentRoom(initialRoom);
    setInitialRoom(initialRoom);
}

int Dungeon::checkGameLogic(){
    if(getPlayer()->checkIsDead()){
        return 0;
    }else{
        if(getPlayer()->getLevel()==20){
            return 1;
        }else{
            return 2;
        }
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
                getPlayer()->setMoney(getPlayer()->getMoney()-15);
                getPlayer()->setCurrentRoom(currentRoom->getUpRoom());
                getPlayer()->currentRoom->roomEvent(getPlayer());
            }
            break;
        }else if(direction=="B"){
            if(currentRoom->getDownRoom()==nullptr){
                cout<<"There is no room"<<endl;
            }else{
                getPlayer()->setMoney(getPlayer()->getMoney()-15);
                getPlayer()->setCurrentRoom(currentRoom->getDownRoom());
                getPlayer()->currentRoom->roomEvent(getPlayer());
            }
            break;
        }else if(direction=="C"){
            if(currentRoom->getLeftRoom()==nullptr){
                cout<<"There is no room"<<endl;
            }else{
                getPlayer()->setMoney(getPlayer()->getMoney()-15);
                getPlayer()->setCurrentRoom(currentRoom->getLeftRoom());
                getPlayer()->currentRoom->roomEvent(getPlayer());
            }
            break;
        }else if(direction=="D"){
            if(currentRoom->getRightRoom()==nullptr){
                cout<<"There is no room"<<endl;
            }else{
                getPlayer()->setMoney(getPlayer()->getMoney()-15);
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
    while(checkGameLogic()==2 && wantNextAction){
        do{
            cout<<"Choose next Action: (A)exit the game (B)move to another room [tolls: 15 dollars] (C)stay in this room (D)show status"<<endl<<"=>";
            cin>>action;
            if(action=="A"){
                wantNextAction = false;
                break;
            }else if(action=="B"){
                if(getPlayer()->getMoney() >= 15){
                    moveToAnotherRoom();
                }else{
                    cout<<"Money is not enough."<<endl;
                }
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
    if(checkGameLogic()==0){
        cout<<"You lose ..."<<endl;
    }else if(checkGameLogic()==1){
        cout<<"You WIN !!!!"<<endl;
    }
    cout<<"End game, see you next time!"<<endl;
}

