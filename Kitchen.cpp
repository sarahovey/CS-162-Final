/**************************************
Author: Sara Hovey
Date: 6/11/17
Description:
**************************************/

#include "Room.hpp"
#include "Kitchen.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Kitchen::Kitchen(std::string name) : Room(name)
{
	//Construct pointers here
}


Kitchen::~Kitchen()
{

}

void Kitchen::flavorText()
{
	cout << "ROOM 3: KITCHEN" << endl;
	cout << "This room must be the kitchen" << endl;
	cout << "Primitive cooking equipment lines the walls." << endl;
	cout << "You hear squeaking. A Rat stops to ponder you," << endl;
	cout << "he looks like he wants to have a chat" << endl;
}

void Kitchen::interact()
{
	if (this->status == false)
	{
		//Interact
		cout << "You chatted awhile with the Rat" << endl;
		cout << "You asked the rat if anyone lived here," << endl;
		cout << "he didn't want to tell you anything valuable." << endl;
		cout << "He seemed much more inclined to complain about today's youth" << endl;
		this->status = true;
	}

	else
	{
		cout << "The rat is gone, there's no one left to talk to" << endl;
	}
}

void Kitchen::search()
{
	if (this->searched == false)
	{
		// List items
		cout << "The only thing left is jars of honey" << endl;
		int size = items.size();
		// List items
		for (int i = 0; i < size; i++)
		{
			cout << items[i]->getName() << endl;
			cout << items[i]->getValue() << endl;
		}

		this->searched = true;
		
	}

	else
	{
		cout << "You've already searched the Kitchen, there's nothing left" << endl;
	}
}

void Kitchen::addItem(Item** item)
{
	items.push_back(*item);
}

void Kitchen::removeItem()
{
	items.pop_back();
}

vector <Item*> Kitchen::getInventory()
{
	return items;
}

void Kitchen::setPtrs(Room* f, Room* b, Room* l, Room* r)
{
	this->forward = f;
	this->backward = b;
	this->left = l;
	this->right = r;
}

int Kitchen::numItems()
{
	int size = items.size();
	return size;
}

bool Kitchen::time()
{
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

bool Kitchen::getSearched()
{
	return this->searched;
}
