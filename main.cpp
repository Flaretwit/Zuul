#include "room.h";
#include "item.h";

using namespace std;

int parseCommand(char* input);

#define WHEREAMI 1
#define EXITS 2
#define GO 3
#define PICKUP 4
#define DROP 5
#define 

int main() {
	vector<Item*> inventory = new vector<Item*>();
	vector<Room*> rooms = new vector<Room*>();
	bool done = false;

	start = currentRoom
	while(!done) {
		Room currentRoom;
		cout << "What do you want to do? (WHEREAMI, EXIT, GO, PICKUP, DROP)" << endl;
	}
	return 0;

}

void pickUp

//parses the command
int parseCommand(char* input) {
	for(int i = 0; i < strlen(input); i++) {
		input[i] = toupper(input[i]);
	} 
	if(!strcmp(input, "WHEREAMI"))
		return WHEREAMI;
	else if(!strcmp(input, "EXITS"))
		return EXITS;
	else if(!strcmp(input, "GO"))
		return GO;
	else if(!strcmp(input, "PICKUP"))
		return PICKUP;
	else if(!strcmp(input, "DROP"))
		return DROP;
	else {
		return 0;
	}
}
