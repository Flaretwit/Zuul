//room.h
#include <iostream>
#include <string.h>
#include <map>
#include <vector>

using namespace std;
//Item struct that only has the variable name
struct Item {
  char* name;
};
//Defines Room's variables and methods

class Room {
 public:
  Room(char*, char*);
  char* getName();
 char* getDescription();
  Room* getExit(int exit);
  void setExit(int direction, Room* nextRoom);
  void addItem(Item* newItem);
  Item* removeItem(char* itemName);
  bool hasItems();
 private:
  char* description;
  char* name;
  map<int, Room*> exitMap;
  vector<Item*> itemList;
};
