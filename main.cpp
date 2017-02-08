#include "room.h"
using namespace std;

#include <vector>
#include <iostream>

#define WHEREAMI 1
#define EXITS 2
#define GO 3
#define PICKUP 4
#define DROP 5

int parseCommand(char* input);
void goRoom(Room*& currentRoom);
int main() {
	vector<Item*> inventory;
	vector<Room*> rooms;
	bool done = false;
	cout << "Welcome to Zuul Adventure, a C++ version of Zuul in Java" << endl;

	Room* start = new Room("Lobby", "You are in a lobby. The alarms appear to be activated. You hear footsteps. What do you do, you are being captured. Escape while you still can!");
	Room *closet = new Room("The Closet", "Seems like any old janitorial closet, or is it?");
	Room *foodstorage = new Room("Pantry", "Looks like you're in the pantry of a restaurant. Lots of yummy food");
	Room *supplyroom = new Room("Supply room", "There's a lot of tools in here. Don't hurt anyone!");
	Room *corridor = new Room("Corridor", "A corridor that connects two far away doors. The ceiling looks awfullly fragile");
	Room *employee = new Room("Door with Dangerous Looking Scanner", "A door with a keycard scanner looms before you. Its quite big. Ramming into it doesn't seem to help though. You'll need a keycard.");
	Room *wait2 = new Room("The Only Waiting Area", "An area that has nothing, wait, really?");
	Room *wait1 = new Room("The One and Only Waiting Area", "This area seems littered with items, why is it so messy?");
	Room *restroom = new Room("Restroom", "A nicely clean bathroom. Don't worry, the bathroom is unisex.");
	Room *stall1 = new Room("Stall 1", "The first stall in the bathroom, cramped and dirty. Who would to use this at all?");
	Room *stall2 = new Room("Stall 2", "The second stall in the bathroom, very spacious. However, it contains nothing in it at all but a toilet.");
	Room *stall3 = new Room("Stall 3", "The third stall, there's no toilet in here?!?");
	Room *diningTables = new Room ("Dining Room with Tables", "Looks like a nice set of tables. They belong the restaurant that they connect to. You can't take these!");
	Room *pub = new Room("Pub", "Are you over 21? If so, head over to the bar to get a drink!");
	Room *bar = new Room("Bar", "A bar. There appears to be no barman, however.");
	Room *restarea = new Room("Lounge Area", "A nice lounge area for the employees of the restaurant. There can't be anything in here, silly!");
	start->setExit(0, closet);
	start->setExit(3, foodstorage);
	start->setExit(2, supplyroom);
	start->setExit(1, corridor);
	closet->setExit(2, start);
	foodstorage->setExit(1, start);
	supplyroom->setExit(0, start);
	corridor->setExit(3, start);
	corridor->setExit(1, employee);
	employee->setExit(3, corridor);
	employee->setExit(1, wait2);
	wait2->setExit(3, employee);
	wait2->setExit(2, wait1);
	wait1->setExit(0, wait2);
	wait1->setExit(2, diningTables);
	diningTables->setExit(0, wait1);
	diningTables->setExit(1, restroom);
	diningTables->setExit(2, pub);
	restroom->setExit(3, diningTables);
	restroom->setExit(0, stall1);
	restroom->setExit(1, stall2);
	restroom->setExit(2, stall3);
	stall1->setExit(2, restroom);
	stall2->setExit(3, restroom);
	stall3->setExit(0, restroom);
	pub->setExit(0, diningTables);
	pub->setExit(3, restarea);
	restarea->setExit(1, pub);
	rooms.push_back(start);
	rooms.push_back(closet);
	rooms.push_back(foodstorage);
	rooms.push_back(supplyroom);
	rooms.push_back(corridor);
	rooms.push_back(employee);
	rooms.push_back(wait2);
	rooms.push_back(wait1);
	rooms.push_back(diningTables);
	rooms.push_back(restroom);
	rooms.push_back(stall1);
	rooms.push_back(stall2);
	rooms.push_back(stall3);
	rooms.push_back(pub);
	rooms.push_back(restarea);
	Room* currentRoom = start;
	while(!done) {
		cout << "What do you want to do/know? (WHEREAMI, EXITS, GO, PICKUP, DROP)" << endl;
		char* input = new char[80];
		cin >> input;
		switch(parseCommand(input)) {
			case WHEREAMI:
				cout << currentRoom->getName() << endl;
				break;
			case EXITS:
				for(int i = 0; i < 4; i++) {
					switch(i) {
						case 0: cout << "NORTH: "; break;
						case 1: cout << "EAST: "; break;
						case 2: cout << "SOUTH: "; break;
						case 3: cout << "WEST: "; break;
					}
					cout << currentRoom->getExit(i)->getName()<<endl;
				}
				break;
			case GO:
				goRoom(currentRoom);
				break;
		}
	}
	return 0;

}
//if requested item is present, removes item from the room and adds it to inventory
void goRoom(Room*& currentRoom) {
	char* input = new char[8];
		cout << "Which direction (N, E, S, W)  would you like to go?" << flush;
		cin >> input;
		if(!strcmp(input, "N")) {
			currentRoom = currentRoom->getExit(0);
			cout << "Executed";
			cout << currentRoom->getName() << endl;
		}
		else if(!strcmp(input, "E")) {
			currentRoom = currentRoom->getExit(1);
		}
		else if(!strcmp(input, "S")) {
			currentRoom = currentRoom->getExit(2);
		}
		else if(!strcmp(input, "W")) {
			currentRoom = currentRoom->getExit(3);
		}
	cin.ignore();
	delete input;
}
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
