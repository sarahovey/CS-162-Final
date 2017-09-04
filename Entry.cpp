/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description:
**************************************/

#include "Room.hpp"
#include "Entry.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Entry::Entry(string name) : Room(name)
{
	//construct all directional pointers here
	//this->forward = 
	//this->backward =
	//this->left = 
	//this->right =
}

Entry::~Entry()
{

}

void Entry::check()
{
    cout << "This is the Entry." << endl;
}

void Entry::lookAround(Room* location)
{
    
}

//First bit that plays 
void Entry::flavorText()
{
	cout << "ROOM 1: ENTRYWAY" << endl;
	cout << "" << endl;
	cout << "You are in the entry way of the great ruin" << endl;
	cout << "Imagine how many honored guests were received here" << endl;
	cout << "It's dark, though. Much too dark to see anything." << endl;
	cout << "What will you do?" << endl;

}

void Entry::menu()
{

}

void Entry::interact()
{
	cout << "You used your fire magic and lit the torches!" << endl;
	this->status = true;
}

void Entry::setPtrs(Room* f, Room* b, Room* l, Room* r)
{
	this->forward = f;
	this->backward = b;
	this->left = l;
	this->right = r;
}

bool Entry::time()
{
	//Prints flavortext given the amount of 
	//actions the player has taken in the current room
	//Increments the actions variable

	//Returning true ends the game
	switch (this->actions)
	{
	case 0:
		cout << "You hear the ruin creak, you better be quick in here..." << endl;
		this->actions++;
		return false;
		break;

	case 1:
		cout << "You hear the ruin creak, you better be quick in here..." << endl;
		this->actions++;
		return false;
		break;
	case 2:
		cout << "The ruin continues creaking, and the room begins to crumble a little" << endl;
		this->actions++;
		return false;
		break;
	case 3:
		cout << "The ruin continues creaking, and crumbling" << endl;
		this->actions++;
		return false;
		break;
	case 4:
		cout << "The ruin continues creaking, and crumbling" << endl;
		this->actions++;
		return false;
		break;
	case 5:
		cout << "The ruin continues creaking, and crumbling" << endl;
		this->actions++;
		return false;
		break;
	case 6:
		cout << "The crumbling intensifies, you better hurry up" << endl;
		this->actions++;
		return false;
		break;
	case 7:
		cout << "The crumbling intensifies, you better hurry up" << endl;
		this->actions++;
		return false;
		break;
	case 8:
		cout << "The crumbling intensifies, you better hurry up" << endl;
		this->actions++;
		return false;
		break;
	case 9:
		cout << "This must be your last action, the horrible sounds being made suggest the need to leave urgently" << endl;
		this->actions++;
		return false;
		break;
	case 10:
		cout << "The room begins to fall apart. You run for your life" << endl;
		cout << "You barely make it out alive, better be more careful next time" << endl;
		cin.ignore();
		return true;
		break;

	default:
		return false;
		break;
	}
	
}

