#include<iostream>
#include"room.h"
using namespace std;

Room::Room(Room *upRoom, Room *downRoom, Room *leftRoom, Room *rightRoom){
    this->upRoom = upRoom;
    this->downRoom = downRoom;
    this->leftRoom = leftRoom;
    this->rightRoom = rightRoom;
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