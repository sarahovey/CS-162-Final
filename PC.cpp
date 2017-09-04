/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description: Implementation file for the PC class. 
Contains virtual attack and defense functions
**************************************/

#include "PC.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

PC::PC(string name) : Character(name)
{

}

PC::~PC()
{

}

Room* PC::getRoom()
{
    return this->location;
}
  
void PC::getInventory()
{
    //Print inventory vector
	int size = this->inventory.size();
//    int weight;
	Item *item;

    for(int i = 0; i<size; i++)
    {
		item = inventory[i];
		item->check();
		cout << "" << endl;
    }
     
	int space;
	space = 50 - size;
	cout << "Space remaining: " << space << endl;
}

void PC::checkItem(Item* item)
{
	item->check();
}

void PC::setLocation(Room* location)
{
	this->location = location;
}
 
 //Collect item from room and place into own inventory
void PC::collect(Room* room)
{
	int size = room->numItems();
	int itemsInBag = inventory.size();

	if (itemsInBag < 50)
	{

		//Get the vector of the Room
		vector<Item*> roomInventory = room->getInventory();

		for (int i = 0; i < size; i++)
		{
			//Push item into inventory
			this->inventory.push_back(roomInventory[i]);

			//remove item from room
			this->location->removeItem();
		}
	}

	else
	{
		cout << "You have too many items in your bag!" << endl;
	}
}
//
//void PC::dropItem(Item* item)
//{
//	inventory.pop_back();
//	//this->location->addItem(item);
//}

void PC::add(Item* item)
{
	this->inventory.push_back(item);
}

bool PC::hasKey()
{
	bool key = false;
	int size = inventory.size();
	std::string name;
	//Search through inventory
	for (int i = 0; i < size; i++)
	{
		name = inventory[i]->getName();
		if (name == "key")
		{
			key = true;
		}
	}

	return key;
}
//void PC::lookAround()
//{
//    Room* location = this->location;
//    
//    //Print name of room
//    cout << "You find yourself in " << location->getName() << endl;
//    // Call virtual function to tell you what you see
//}
