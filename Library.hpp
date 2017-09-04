/********************************
Author: Sara Hovey

Description:
********************************/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "Character.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>
class Library :
	public Room
{
private:
	bool key;
public:
	Library(std::string name);
	~Library();

	virtual void flavorText();
	virtual void interact();
	virtual void setPtrs(Room* f, Room* b, Room* l, Room* r);
	virtual bool time();

};


#endif
