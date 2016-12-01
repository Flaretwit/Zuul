//item.h
#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <iostream>
#include <string.h>


class Item() {
	public:
		Item();
		virtual ~Item();
		char* getDescription();
	protected:
		char* description;

}



#endif
