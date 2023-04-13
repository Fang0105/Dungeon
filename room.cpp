#include<iostream>
#include"room.h"
#include"battle.h"
#include"npc.h"
using namespace std;

Room::Room(){
    this->tag = "initialRoom";
}

Room::Room(Room *upRoom, Room *downRoom, Room *leftRoom, Room *rightRoom){
    this->upRoom = upRoom;
    this->downRoom = downRoom;
    this->leftRoom = leftRoom;
    this->rightRoom = rightRoom;
    this->tag = "initialRoom";
}

void Room::setUpRoom(Room *upRoom){
    this->upRoom = upRoom;
}

void Room::setDownRoom(Room *downRoom){
    this->downRoom = downRoom;
}

void Room::setLeftRoom(Room *leftRoom){
    this->leftRoom = leftRoom;
}

void Room::setRightRoom(Room *rightRoom){
    this->rightRoom = rightRoom;
}

void Room::setFourRoom(Room *upRoom,Room *downRoom,Room *leftRoom,Room *rightRoom){
    setUpRoom(upRoom);
    setDownRoom(downRoom);
    setLeftRoom(leftRoom);
    setRightRoom(rightRoom);
}

void Room::setTag(string tag){
    this->tag = tag;
}

Room* Room::getUpRoom(){
    return this->upRoom;
}

Room* Room::getDownRoom(){
    return this->downRoom;
}

Room* Room::getLeftRoom(){
    return this->leftRoom;
}

Room* Room::getRightRoom(){
    return this->rightRoom;
}

string Room::getTag(){
    return this->tag;
}

TreasureRoom::TreasureRoom(){
    this->tag = "TreasureRoom";
    this->getTreasure = false;
}

TreasureRoom::TreasureRoom(Weapon dropWeapon,int dropMoney,Room *upRoom, Room *downRoom, Room *leftRoom, Room *rightRoom):Room(upRoom,downRoom,leftRoom,rightRoom){
    this->dropWeapon = dropWeapon;
    this->dropMoney = dropMoney;
    this->tag = "TreasureRoom";
    this->getTreasure = false;
}

void TreasureRoom::setDropWeapon(Weapon dropWeapon){
    this->dropWeapon = dropWeapon;
}

void TreasureRoom::setDropMoney(int dropMoney){
    this->dropMoney = dropMoney;
}

Weapon TreasureRoom::getDropWeapon(){
    return this->dropWeapon;    
}

int TreasureRoom::getDropMoney(){
    return this->dropMoney;
}

MonsterRoom::MonsterRoom(){
    this->tag = "MonsterRoom";
}

MonsterRoom::MonsterRoom(Monster* monster,Room *upRoom, Room *downRoom, Room *leftRoom, Room *rightRoom):Room(upRoom,downRoom,leftRoom,rightRoom){
    this->monster = monster;
    this->tag = "MonsterRoom";
}

void MonsterRoom::setMonster(Monster* monster){
    this->monster = monster;
}

Monster* MonsterRoom::getMonster(){
    return this->monster;
}

NPCRoom::NPCRoom(){
    this->tag = "NPCRoom";
}

NPCRoom::NPCRoom(NPC* npc,Room *upRoom, Room *downRoom, Room *leftRoom, Room *rightRoom):Room(upRoom,downRoom,leftRoom,rightRoom){
    this->npc = npc;
    this->tag = "NPCRoom";
}

void NPCRoom::setNPC(NPC* npc){
    this->npc = npc;
}

NPC* NPCRoom::getNPC(){
    return this->npc;
}

void Room::roomEvent(Player* player){
    cout<<"[InitialRoom]"<<endl;
    cout<<"There is nothing to do in this room"<<endl;
}

void MonsterRoom::roomEvent(Player* player){
    cout<<"[MonsterRoom]"<<endl;
    string fight;
    do{
        cout<<"Do you want to fight with monster? (A)Yes (B)No"<<endl<<"=>";
        //cin.ignore();
        getline(cin,fight);
        if(fight=="A"){
            battleSystem(player,getMonster());
            break;
        }else if(fight=="B"){
            break;
        }else{
            cout<<fight<<" is no a choice"<<endl;
        }
    }while(true);
}

void TreasureRoom::roomEvent(Player* player){
    cout<<"[TreasureRoom]"<<endl;
    if(this->getTreasure==true){
        cout<<"You have gotten the treasure already"<<endl;
    }else{
        cout<<"You find a treasure!!!"<<endl;
        string choice;
        do{
            cout<<"Do you want to open it now? (A)Yes (B)No"<<endl<<"=>";
            //cin.ignore();
            getline(cin,choice);
            if(choice=="A"){
                cout<<"You find a weapon: "<<getDropWeapon()<<", and ["<<getDropMoney()<<" dollars]"<<endl;
                player->setMoney(player->getMoney()+getDropMoney());
                player->getNewWeapon(getDropWeapon());
                this->getTreasure = true;
                break;
            }else if(choice=="B"){
                cout<<"say byebye to the treasure~"<<endl;
                break;
            }else{
                cout<<choice<<" is not a choice"<<endl;
            }
        }while(true);
    }
}

void NPCRoom::roomEvent(Player* player){
    cout<<"[NPCRoom]"<<endl;
    cout<<"I'm "<<getNPC()->getName()<<"..."<<getNPC()->getScript()<<endl;
    string buySomething;
    do{
        cout<<"Want to buy something? (A)Yes (B)No"<<endl<<"=>";
        //cin.ignore();
        getline(cin,buySomething);
        if(buySomething=="A"){
            int idx = getNPC()->buyCommodity(player->getMoney());
            if(idx==-2){
                player->setMoney(player->getMoney()-20);
                continue;
            }else if(idx!=-1){
                player->getNewWeapon(getNPC()->getCommodity()[idx].getWeapon());
                player->setMoney(player->getMoney() - getNPC()->getCommodity()[idx].getPrice());
                vector<Commodity>oldCommodity = getNPC()->getCommodity();
                vector<Commodity>newCommodity;
                for(int i=0;i<oldCommodity.size();i++){
                    if(i!=idx){
                        newCommodity.push_back(oldCommodity[i]);
                    }
                }
                getNPC()->setCommodity(newCommodity);
                if(getNPC()->getCommodity().size()==0){
                    getNPC()->setCommodity(generateCommodities());
                }
            }
            break;
        }else if(buySomething=="B"){
            cout<<"alright...bye bye"<<endl;
            break;
        }else{
            cout<<buySomething<<" is not a choice"<<endl;
        }
    }while(true);
     
}