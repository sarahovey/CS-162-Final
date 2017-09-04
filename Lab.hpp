/********************************
Author: Sara Hovey

Description:
********************************/

#ifndef LAB_HPP
#define LAB_HPP
#include "Character.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>
class Lab :
	public Room
{
private:
	bool key;
public:
	Lab(std::string name);
	~Lab();

	virtual void flavorText();
	virtual void flavorText2();
	virtual void interact();
	virtual void interact2();
	virtual void search();
	virtual void addItem(Item** item);
	virtual void removeItem();
	virtual int numItems();
	virtual void setKey();
	virtual bool time();

	virtual vector <Item*> getInventory();
	virtual void setPtrs(Room* f, Room* b, Room* l, Room* r);

	virtual bool getSearched();
};


#endif
