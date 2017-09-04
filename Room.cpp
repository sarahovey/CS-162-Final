/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description:
**************************************/

#include "Room.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


// Other data members are going to be vectors of objects
//How to construct them?
Room::Room(string name)
{
	this->name = name;
	this->status = false;
	this->searched = false;
	this->actions = 0;
	//this->forward = forward;
	//this->backward = backward;
	//this->left = left;
	//this->right = right;
	//
}

Room::~Room()
{

}

std::string Room::getName()
{
	return name;
}

void Room::setPtrs(Room* f, Room* b, Room* l, Room* r)
{
	cout << "Can't set from here" << endl;
}

void Room::getItems()
{
    //Prints all items in room
}

//The flavortext that shows the first time you enter a room
void Room::flavorText()
{
	cout << "I can't show you from here!" << endl;
}

void Room::flavorText2()
{
	cout << "I can't show you from here" << endl;
}

void Room::interact2()
{
	cout << "I can't intereact from here!" << endl;
}

void Room::setKey()
{

}

void Room::interact()
{
	cout << "Can't do anything from here!" << endl;
}

void Room::search()
{
	cout << "Nothing to search for here!" << endl;
}

void Room::addItem(Item** item)
{

}

void Room::removeItem()
{
	cout << "Can't remove from here!" << endl;
}

int Room::numItems()
{
	//returns number of items in room's inventory
	cout << "Can't return from here" << endl;
	return 0;
}

vector<Item*> Room::getInventory()
{
	cout << "cannot return inventory from here" << endl;
	return items;
}

bool Room::time()
{
	cout << "Cant time from here!" << endl;
	//This function provides flavortext and increments
	// the actions var by 1
	return false;
}

bool Room::getSearched()
{
	return this->searched;
}

int Room::getActions()
{
	return this->actions;
}

void Room::setActions(int actions)
{
	this->actions = actions;
}
