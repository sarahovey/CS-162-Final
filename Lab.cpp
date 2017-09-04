/**************************************
Author: Sara Hovey
Date: 5/14/17
Description:
**************************************/

#include "Room.hpp"
#include "Lab.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Lab::Lab(std::string name) : Room(name)
{
	//Construct pointers here

	//Key variable, for last Lab
	this->key = false;
}


Lab::~Lab()
{

}

void Lab::flavorText()
{
	cout << "ROOM 2: LAB" << endl;
	cout << "You find yourself in the alchemy lab of some old mage" << endl;
	cout << "There has got to be some ingredients in here worth stashing" << endl;
	cout << "But the burner is still on... someone was obviously in here recently" << endl;
	cout << "If someone lives here, they're not very organized." << endl;
	cout << "you've always prided yourself on your organizational abilities, and quietly judge the person who lives here" << endl;

}

void Lab::flavorText2()
{

	cout << "ROOM 5: LAB 2" << endl;
	cout << "You reach the final room that isn't locked...." << endl;
	cout << "This looks less like an alchemy lab, and more like a spell-working lab" << endl;
	cout << "Books and scrolls are everywhere. It really looks like someone lives here" << endl;
	cout << "There is even a huge pair of glasses sitting on the table" << endl;
	cout << "And scorch marks everywhere." << endl;
	
}

void Lab::interact2()
{

	if (this->key == false)
	{
		cout << "You use your magic to tidy the place up" << endl;
		cout << "While straightening some of illegible scrolls, you notice something fall on the floor" << endl;
		cout << "Its..." << endl;
		cout << "A set of KEYS held together by an obnoxiously pink lanyard" << endl;
	}

	else
	{
		cout << "You've already tidied!" << endl;
	}
}

void Lab::interact()
{
	if (this->status == false)
	{
		//Interact
		cout << "You put out the flame in the alchemy stove." << endl;
		cout << "This place is already a ruin, no sense in letting some fire get started" << endl;
		this->status = true;
	}

	else
	{
		cout << "You've already turned the burner off. Not much else to do here" << endl;
	}
}

void Lab::search()
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
		cout << "You've already searched the Lab, there's nothing left" << endl;
	}
}

void Lab::addItem(Item** item)
{
	items.push_back(*item);
}

void Lab::removeItem()
{
	items.pop_back();
}

int Lab::numItems()
{
	int size = items.size();
	return size;
}

vector<Item*> Lab::getInventory()
{
	return items;
}

void Lab::setKey()
{
	// sets key value
	this->key = true;
}

void Lab::setPtrs(Room* f, Room* b, Room* l, Room* r)
{
	this->forward = f;
	this->backward = b;
	this->left = l;
	this->right = r;
}

bool Lab::time()
{
	//Returning true ends the game
	int num = this->actions;
	switch (num)
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

bool Lab::getSearched()
{
	return this->searched;
}