/**************************************
Author: Sara Hovey
Date: 5/14/17
Description:
**************************************/

#include "Room.hpp"
#include "DiningHall.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

DiningHall::DiningHall(std::string name) : Room(name)
{
	//Construct pointers here
}


DiningHall::~DiningHall()
{

}

void DiningHall::flavorText()
{
	cout << "ROOM 4: DINING HALL" << endl;
	cout << "You reach a vast Dining Hall" << endl;
	cout << "This must be where feasts were held" << endl;
	cout << "Like everywhere else, this place is a real mess" << endl;
	cout << "Seems like there are a few more intersting odds and ends here, though" << endl;
	cout << "..." << endl;
	cout << "You notice a pretty big piece of shed scales near the hearth" << endl;
	cout << "This can't be good" << endl;
	cout << "You're mildly bothered, but have a tendency to go with things that may" << endl;
	cout << "not be the best idea, so you keep moving anyway" << endl;
}

void DiningHall::interact()
{
	if (this->status == false)
	{
		//Interact
		cout << "You used your magic to push the benches in and dust a bit" << endl;
		cout << "Maybe that rat will think twice about complaining about ~kids these days~ next time" << endl;
		cout << "It looks a little better now." << endl;

		status = true;
	}

	else
	{
		cout << "You have already tidied" << endl;
	}
}

void DiningHall::search()
{
	if (this->searched == false)
	{
		// List items
		int size = items.size();
		for (int i = 0; i < size; i++)
		{
			cout << items[i]->getName() << endl;
			cout << items[i]->getValue() << endl;
		}

		this->searched = true;
	}

	else
	{
		cout << "You've already searched the Dining Hall, there's nothing left" << endl;
	}
}

void DiningHall::addItem(Item** item)
{
	items.push_back(*item);
}

void DiningHall::removeItem()
{
	items.pop_back();
}

vector <Item*> DiningHall::getInventory()
{
	return items;
}

void DiningHall::setPtrs(Room* f, Room* b, Room* l, Room* r)
{
	this->forward = f;
	this->backward = b;
	this->left = l;
	this->right = r;
}

int DiningHall::numItems()
{
	int size = items.size();
	return size;
}

bool DiningHall::time()
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

bool DiningHall::getSearched()
{
	return this->searched;
}