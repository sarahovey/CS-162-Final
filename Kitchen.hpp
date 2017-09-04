/********************************
Author: Sara Hovey

Description:
********************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "Room.hpp"
#include <string>
#include <vector>
class Kitchen :
	public Room
{
public:
	Kitchen(std::string name);
	~Kitchen();

	virtual void flavorText();
	virtual void interact();
	virtual void search();
	virtual void addItem(Item** item);
	virtual void removeItem();
	virtual vector<Item*> getInventory();
	virtual void setPtrs(Room* f, Room* b, Room* l, Room* r);
	virtual int numItems();
	virtual bool time();
	virtual bool getSearched();

};

#endif

