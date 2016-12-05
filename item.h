//item.h
#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <iostream>
#include <string.h>


class Item() {
	public:
		Item(char*, char*);
		virtual ~Item();
		char* getDescription();
		char* getName();
	protected:
		char* description;

}



#endif
