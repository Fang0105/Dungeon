#include<iostream>
#include"room.h"
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
}

TreasureRoom::TreasureRoom(Weapon dropWeapon,int dropMoney,Room *upRoom, Room *downRoom, Room *leftRoom, Room *rightRoom):Room(upRoom,downRoom,leftRoom,rightRoom){
    this->dropWeapon = dropWeapon;
    this->dropMoney = dropMoney;
    this->tag = "TreasureRoom";
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