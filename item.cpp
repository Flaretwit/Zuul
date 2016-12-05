#include <vector>
#include <string.h>
//Item.cpp


using namespace std;


Item::Item() {
	description = new char[80];
	name = new char[80];
}

char* Item::getDescription() {
	return description;
}

char* Item::getName() {
	return name;
}



