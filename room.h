//room.h
#include <string.h>
#include <vector>

class Room {

	public:
		Room();
		virtual ~Room();
		vector<Item*> *storage = new vector<Item*>();
	private:
		char* description;
	
};
