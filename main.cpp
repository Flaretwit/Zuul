#include "room.h";
#include "item.h";

using namespace std;

int parseCommand(char* input);
int pickUp
#define WHEREAMI 1
#define EXITS 2
#define GO 3
#define PICKUP 4
#define DROP 5

int main() {
	vector<Item*> inventory = new vector<Item*>();
	vector<Room*> rooms = new vector<Room*>();
	bool done = false;
	cout << "Welcome to Zuul Adventure, a C++ version of Zuul in Java << endl;
	
	Room* start = new Room("You are in a lobby. The alarms appear to be activated. You hear footsteps. What do you do, you are being captured. Escape while you still can!");
	Room *closet = new Room("Seems like any old janitorial closet, or is it?");
	Room *foodstorage = new Room("Looks like you're in the pantry of a restaurant. Lots of yummy food");
	Room *supplyroom = new Room("There's a lot of tools in here. Don't hurt anyone!");
	Room *corridor = new Room("A corridor that connects two far away doors. The ceiling looks awfullly fragile");
	Room *employee = new Room("A door with a keycard scanner looms before you. Its quite big. Ramming into it doesn't seem to help though. You'll need a keycard.");
	Room *wait2 = new Room("An area that has nothing, wait, really?");
	Room *wait1 = new Room("This area seems littered with items, why is it so messy?");
	Room *restroom = new Room("A nicely clean bathroom. Don't worry, the bathroom is unisex.");
	Room *stall1 = new Room("The first stall in the bathroom, cramped and dirty. Who would to use this at all?");
	Room *stall2 = new Room("The second stall in the bathroom, very spacious. However, it contains nothing in it at all but a toilet.");
	Room *stall3 = new Room("The third stall, there's no toilet in here?!?");
	Room *diningTables = new Room ("Looks like a nice set of tables. They belong the restaurant that they connect to. You can't take these!");
	Room *pub = new Room("Are you over 21? If so, head over to the bar to get a drink!");
	Room *bar = new Room("A bar. There appears to be no barman, however.");
	Room *restarea = new Room("A nice lounge area for the employees of the restaurant. There can't be anything in here, silly!");
	start.setExit(0, closet);
	start.setExit(3, foodstorage);
	start.setExit(2, supplyroom);
	start.setExit(1, corridor);
	closet.setExit(2, start);
	foodstorage.setExit(1, start);
	supplyroom.setExit(0, start);
	corridor.setExit(3, start);
	corridor.setExit(1, employee);
	employee.setExit(3, corridor);
	employee.setExit(1, wait2);
	wait2.setExit(3, employee);
	wait2.setExit(2, wait1);
	wait1.setExit(0, wait2);
	wait1.setExit(2, diningTables);
	diningTables.setExit(0, wait1);
	diningTables.setExit(1, restroom);
	diningTables.setExit(2, pub);
	restroom.setExit(3, diningTables);
	restroom.setExit(0, stall1);
	restroom.setExit(1, stall2);
	restroom.setExit(2, stall3);
	stall1.setExit(2, restroom);
	stall2.setExit(3, restroom);
	stall3.setExit(0, restroom);
	pub.setExit(0, diningTables);
	pub.setExit(3, restarea);
	restarea.setExit(1, pub);
	rooms.add(start);
	rooms.add(closet);
	rooms.add(foodstorage);
	rooms.add(supplyroom);
	rooms.add(corridor);
	rooms.add(employee);
	rooms.add(wait2);
	rooms.add(wait1);
	rooms.add(diningTables);
	rooms.add(restroom);
	rooms.add(stall1);
	rooms.add(stall2);
	rooms.add(stall3);
	rooms.add(pub);
	rooms.add(restarea);
	Room* currentRoom = start;	
	while(!done) {
		cout << "What do you want to do/know? (WHEREAMI, EXITS, GO, PICKUP, DROP)" << endl;
		char* input[80];
		cin >> input;
		switch(parseCommand(input)) {
			case WHERAMI:
				cout << currentRoom->getName() << endl;
				break;
			case EXITS:
				for(int i = 0; i < 4; i++) {
	
		}
	}
	return 0;

}
//if requested item is present, removes item from the room and adds it to inventory 

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
