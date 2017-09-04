/********************************
Author: Sara Hovey

Description:
********************************/

#ifndef DININGHALL_HPP
#define DININGHALL_HPP
#include "Room.hpp"
#include <string>
#include <vector>
class DiningHall :
	public Room
{
public:
	DiningHall(std::string name);
	~DiningHall();

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
	//virtual int getActions();
};

#endif

