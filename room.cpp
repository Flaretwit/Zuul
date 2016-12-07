//room.cpp
#include <vector>	
#include <iostream>
#include "room.h"
	
using namespace std;
//the room constructor
Room::Room(char* name, char* description) {
	this.name = name;
	this.description = description;
}

void Room::setExit(int direction, Room room) {
	exits[direction] = room;
}

Room Room::getExit(int direction) {
	return (Room) exits.get(direction);
}
//checks if the room contains such item
bool Room::contains(Item *item) {
	for(int i = 0; i < sizeof(storage); i++) {
		if(!strcmp(storage->at(i)->name, item->name))
			return true;
	}
	return false;
}

