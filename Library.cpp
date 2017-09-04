/**************************************
Author: Sara Hovey
Date: 5/14/17
Description:
**************************************/

#include "Room.hpp"
#include "Library.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Library::Library(std::string name) : Room(name)
{

}


Library::~Library()
{

}

void Library::flavorText()
{
	cout << "FINAL ROOM: LIBRARY" << endl;
	cout << "You find yourself in a massive library" << endl;
	cout << "This space is most definitely lived in" << endl;
	cout << "You know this because there is a very large, very alive dragon" << endl;
	cout << "sitting in a large, makeshift chair near the fire" << endl;
	cout << " " << endl;
}

void Library::interact()
{
	if (this->status == false)
	{
		//Interact
		cout << "The dragon turns to you suddenly..." << endl;
		cout << "'Thanks for finding my keys!'" << endl;

		cout << "You sheepishly give them their keys" << endl;
		cout << "The dragon asked 'Are you the new housekeeper? One of the rats who lives here said'" << endl;
		cout << "'that someone was running around cleaning everything'" << endl;
		cout << "" << endl;
		cout << "You inform the dragon that you are not, in fact, the new housekeeper" << endl;
		cout << "The dragon laughed, 'What are you doing here, then? The last of the real treasure was pilfered'" << endl;
		cout << "'years and years ago. Between adventurers like you and hoarders like me, there hasn't been anything left in awhile,'" << endl;
		cout << "'except for bits of honey, and potion ingredients, but no one usually wants those'" << endl;
		cout << "" << endl;
		cin.ignore();

		cout << "You tell the dragon about why you decided to strike out and hunt treasure" << endl;
		cout << "Treasure hunting and adventuring is really not your thing, you explain" << endl;
		cout << "But you really need gold for books. And some new robes couldn't hurt, either" << endl;
		cout << "...." << endl;

		cin.ignore();
		cout << "" << endl;


		cout << "The dragon considers what you've said" << endl;
		cout << "'I'll tell you what, ' the dragon says " << endl;
		cout << "'I just moved in here, and this place is an awful mess, '" << endl;
		cout << "'and your magic seems pretty effective at sorting things out.'" << endl;
		cout << "'If you help me get this place livable, I'll give you some gold and gems to '" << endl;
		cout << "'pay for books and robes. You can also help yourself to whatever treasure is left'" << endl;

		cout <<  "...." << endl;
		cin.ignore();

		cout << "You gladly agree to the dragon's request," << endl;
		cout << "this should turn out to be an interesting summer job." << endl;

		this->status = true;
	}

	else
	{
		cout << "You've already talked with the dragon" << endl;
	}
}

void Library::setPtrs(Room* f, Room* b, Room* l, Room* r)
{
	this->forward = f;
	this->backward = b;
	this->left = l;
	this->right = r;
}

bool Library::time()
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






