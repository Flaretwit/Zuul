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
bool containsItem(char* itemName, vector<Item*> inventory);
void pickUp(Room*& currentRoom, vector<Item*> &inventory);
Item* removeFrom(char* itemName, vector<Item*> &inventory);
void drop(Room*& currentRoom, vector<Item*> &inventory);
int main() {
	vector<Item*> inventory;
	vector<Room*> rooms;
	bool done = false;
	cout << "Welcome to Zuul Adventure, a C++ version of Zuul in Java" << endl;
	cout << "You have twenty turns to get to the exit, but where is it?" << endl;
	//Initalizes rooms
	Room* start = new Room((char*)"Lobby",(char*) "You are in a lobby. The alarms appear to be activated. You hear footsteps. What do you do, you are being captured. Escape while you still can!");
	Room *closet = new Room((char*)"The Closet",(char*) "Seems like any old janitorial closet, or is it?");
	Room *foodstorage = new Room((char*)"Pantry",(char*) "Looks like you're in the pantry of a restaurant. Lots of yummy food");
	Room *supplyroom = new Room((char*)"Supply room",(char*) "There's a lot of tools in here. Don't hurt anyone!");
	Room *corridor = new Room((char*)"Corridor",(char*) "A corridor that connects two far away doors. The ceiling looks awfullly fragile");
	Room *employee = new Room((char*)"Door with Dangerous Looking Scanner",(char*) "A door with a keycard scanner looms before you. Its quite big. Ramming into it doesn't seem to help though. You'll need a keycard.");
	Room *wait2 = new Room((char*)"The Only Waiting Area",(char*) "An area that has nothing, wait, really?");
	Room *wait1 = new Room((char*)"The One and Only Waiting Area",(char*) "This area seems littered with items, why is it so messy?");
	Room *restroom = new Room((char*)"Restroom",(char*) "A nicely clean bathroom. Don't worry, the bathroom is unisex.");
	Room *stall1 = new Room((char*)"Stall 1",(char*) "The first stall in the bathroom, cramped and dirty. Who would to use this at all?");
	Room *stall2 = new Room((char*)"Stall 2",(char*) "The second stall in the bathroom, very spacious. However, it contains nothing in it at all but a toilet.");
	Room *stall3 = new Room((char*)"Stall 3", (char*)"The third stall, there's no toilet in here?!?");
	Room *diningTables = new Room ((char*)"Dining Room with Tables",(char*) "Looks like a nice set of tables. They belong the restaurant that they connect to. You can't take these!");
	Room *pub = new Room((char*)"Pub",(char*) "Are you over 21? If so, head over to the bar to get a drink!");
	Room *bar = new Room((char*)"Bar",(char*) "A bar. There appears to be no barman, however.");
	Room *restarea = new Room((char*)"Lounge Area",(char*) "A nice lounge area for the employees of the restaurant. There can't be anything in here, silly!");
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
	//Sets items
	Item* keycard = new Item();
	Item* fishingtwine = new Item();
	Item* cup = new Item();
	Item* plate = new Item();
	Item* card = new Item();

	card->name = (char*)"Card";
	cup->name =(char*) "Cup";
	plate->name = (char*)"Plate";
	keycard->name = (char*) "Keycard";
	fishingtwine->name = (char*)"Fishing Twine";
	closet->addItem(keycard);
	closet->addItem(cup);
	supplyroom->addItem(keycard);
	diningTables->addItem(plate);
	foodstorage->addItem(fishingtwine);
	//adds all the rooms to the vector
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

	int turncount = 0;
	Room* currentRoom = start;
	cout << currentRoom->getDescription() << endl;
	while(!done) {
		//checks conditions for win or loss.
		if(turncount >= 20) {
			cout << "You lost! Time expired and you were captured!" << endl;
			cout << "Score: FAILURE" << endl;
			break;
		}
		if(currentRoom->getExit(1) != NULL) {
		if(!strcmp(currentRoom->getName(), "Door with Dangerous Looking Scanner")
			&& !containsItem((char*)"Keycard", inventory)) {
				cout << "You lost! You were fried by the laser!" << endl;
				break;
		}}
		if(!strcmp(currentRoom->getName(), "Pub")) {
			cout << "You won the game in " << turncount << " turns!"<<endl;
			break;
		}
		cout << "Turn: " << turncount << endl;
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
						case 0: cout << "NORTH: " ; break;
						case 1: cout << "EAST: "; break;
						case 2: cout << "SOUTH: "; break;
						case 3: cout << "WEST: "; break;
					}
					if(currentRoom->getExit(i) != NULL) {
					cout << currentRoom->getExit(i)->getName()<< endl;
					}
					else {
						cout << endl;
					}
				}
				break;
			case GO:
				goRoom(currentRoom);
				cout << currentRoom->getName() << flush;
				cout << ": " << currentRoom->getDescription() << endl;
				turncount++;
				break;
			case PICKUP:
				pickUp(currentRoom, inventory);
				break;
			case DROP:
				drop(currentRoom, inventory);
				break;
		}
	}
	return 0;
}
void drop(Room*&currentRoom, vector<Item*>& inventory) {
	cout << "The following items are in your inventory: " << endl;
	for (int i = 0; i < inventory.size(); i++) {
			cout << inventory.at(i)->name << endl;
	}
	cout << "What item would you like to drop?" << endl;
	char input[80];
	cin >> input;
	Item* temp = new Item();
	if((temp = removeFrom(input, inventory)) != NULL) {
		currentRoom->itemList.push_back(temp);
		return;
	}
	cout << "That item doesn't exist in your inventory." << endl;
}
//picks up an item
void pickUp(Room*&currentRoom, vector<Item*>& inventory) {
	if(currentRoom->hasItems()) {
	cout << "The following items are in the room: " << endl;
	for (int i = 0; i < currentRoom->itemList.size(); i++) {
			cout << currentRoom->itemList.at(i)->name << endl;
	}
	cout << "What item would you like to pick up?" << endl;
	char input[80];
	cin >> input;

	Item* temp = new Item();
	if((temp = currentRoom->removeItem(input)) != NULL) {
		inventory.push_back(temp);
		return;
	}
	cout << "That item doesn't exist in the room." << endl;
	return;
} else {
	cout << "No items in the Room to pick up. " << endl;
}


}

//checks if inventory contains said item.
bool containsItem(char* itemName, vector<Item*> inventory) {
  for (int i = 0; i < inventory.size(); i++) {
    if (!strcasecmp(itemName, inventory.at(i)->name)) {
    	return true;
    }
  }
	return false;
}
//if requested item is present, removes item from the room and adds it to inventory
void goRoom(Room*& currentRoom) {
	char input[80];
		cout << "Which direction (N, E, S, W)  would you like to go?" << flush;
		cin >> input;
		if(!strcmp(input, "N")) {
			currentRoom = currentRoom->getExit(0);
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

Item* removeFrom(char* itemName, vector<Item*> &inventory) {
  for (int i = 0; i < inventory.size(); i++) {
    if (!strcasecmp(itemName, inventory.at(i)->name)) {
      Item* returnedItem = inventory.at(i);
      inventory.erase(inventory.begin() + i);
      return returnedItem;
    }
  }
  return NULL;
}
