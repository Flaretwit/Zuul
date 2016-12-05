//room.cpp
#include <vector>	
#include <iostream>
#include "room.h"
	
using namespace std;

Room::Room(char* name, char* description) {
	this.name = name;
	this.description = description;
}

void setExit(int direction, Room room) {
	exits[direction] = room;
}




