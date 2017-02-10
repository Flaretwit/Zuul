
#include "room.h"
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
//Room.cpp
//Contains methods outlined in Room.h
using namespace std;
//Room constructor
Room::Room(char* newName, char* newDescription) {
 name = newName;
 description = newDescription;
}
//returns the name of the room
char* Room::getName() {
  return name;
}
//returns the room description
char* Room::getDescription() {
 return description;
}
//returns the exit of the room in the given direction.
Room* Room::getExit(int exit) {
 map<int, Room*>::iterator it = exitMap.find(exit);
 if (it != exitMap.end())
  return exitMap.find(exit)->second;
 return NULL;
}
//allows you to set an exit to a Room in the form of a Room pointer
void Room::setExit(int direction, Room* nextRoom) {
  exitMap[direction] = nextRoom;
}
//adds an Item to the room.
void Room::addItem(Item* newItem) {
  itemList.push_back(newItem);
}
//removes an Item and works if item is not found
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
//checks if the room even has items
bool Room::hasItems() {
  if (itemList.empty())
    return false;
  return true;
}
