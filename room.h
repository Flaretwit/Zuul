//room.h
#include <string.h>
#include <vector>
#include "item.h"

class Room {
	public:
		Room(char*, char*);
		virtual ~Room();
		vector<Item*> *storage = new vector<Item*>();
		Map<int, Room> exits = new Map<int, Room>();
		void setExit(int direction, Room room);
		
	private:
		char* description;
		char* name;
	
};
