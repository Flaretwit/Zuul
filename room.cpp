
#include "room.h"
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
//Room.cpp
//Contains methods outlined in Room.h
using namespace std;


Room::Room(char* newName, char* newDescription) {
 name = newName;
 description = newDescription;
}

char* Room::getName() {
  return name;
}

char* Room::getDescription() {
 return description;
}
Room* Room::getExit(int exit) {
 map<int, Room*>::iterator it = exitMap.find(exit);
 if (it != exitMap.end())  
  return exitMap.find(exit)->second;
 return NULL;
}

void Room::setExit(int direction, Room* nextRoom) {
  exitMap[direction] = nextRoom;
}

void Room::addItem(Item* newItem) {
  itemList.push_back(newItem);
}

Item* Room::removeItem(char* itemName) {
  for (int i = 0; i < itemList.size(); i++) {
    if (!strcasecmp(itemName, itemList.at(i)->name)) {
      Item* returnedItem = itemList.at(i);
      itemList.erase(itemList.begin() + i);
      return returnedItem;
    }
  }
  return NULL;
}

bool Room::hasItems() {
  if (itemList.empty())
    return false;
  return true;
}
