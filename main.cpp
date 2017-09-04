/********************************
Author: Sara Hovey  
Date: 6/11/17
Description: Main file for 162 final project
Creates objects and drives the game.
Handles interactions between the objects
********************************/

/*******************************
Win condition: collect the keys,
in the library,
which triggers the end event
*******************************/

//Items
#include "Item.hpp"
#include "Honey.hpp"
#include "Ingredient.hpp"
#include "Book.hpp"
#include "Artifact.hpp"

//Rooms
#include "Room.hpp"
#include "Entry.hpp"
#include "Lab.hpp"
#include "Kitchen.hpp"
#include "DiningHall.hpp"
#include "Library.hpp"

//Characters
#include "Character.hpp"
#include "PC.hpp"

//Other
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*****************************
Function prototypes
*****************************/
void title();
void introText();
void storyDriver(PC* player, Room* e1, Room* lab1, Room* k1, Room* d1, Room* l2, Room* lib, Item* key);
void entryDriver(Room* e1, PC* player);
void labDriver(Room* lab1, PC* player);
void kitchenDriver(Room* k1, PC* player);
void diningDriver(Room* d1, PC* player);
void Lab2Driver(Room* l2, PC* player, Item* key);
void libraryDriver(Room* lib, PC* player);
void win(PC* player);
void loss(PC* player);
void thx();
void timeUpText(PC* player);

//Helper functions
int getData(int min, int max);
bool validateInt(int data, int min, int max);
//void getActions(Room* room, PC* player);


/*****************************
Main
*****************************/
int main()
{
    //Create Items
    
	//Create books
	Item* book1 = new Book("Book with an illegible title", 25);
	Item* book2 = new Book("Book with an illegible title", 25);
	Item* book3 = new Book("Book with an illegible title", 25);
	Item* book4 = new Book("Scroll coverd in Runes", 25);
	Item* book5 = new Book("Scroll covered in huge chicken scratch", 25);
	Item* book6 = new Book("Empty scroll", 25);

	//Create Ingredients
	Item* in1 = new Ingredient("Ingredient: Moss", 10);
	Item* in2 = new Ingredient("Ingredient: Moth wings", 15);
	Item* in3 = new Ingredient("Ingredient: Seed pods", 5);
	Item* in4 = new Ingredient("Ingredient: Elf hair", 100);
	Item* in5 = new Ingredient("Ingredient: Bottled moonlight", 30);
	Item* in6 = new Ingredient("Ingredient: A whole bee", 5);
	Item* in7 = new Ingredient("Ingredient: Bone meal", 75);
	Item* in8 = new Ingredient("Ingredient: Ashes", 40);
	Item* in9 = new Ingredient("Ingredient: Tree bark", 20);
	Item* in10 = new Ingredient("Ingredient: Blood?", 50);
    
	//Create Honey
	Item* h1 = new Honey("Ancient Honey", 10);
	Item* h2 = new Honey("Ancient Honey", 10);
	Item* h3 = new Honey("Ancient Honey", 10);
	Item* h4 = new Honey("Ancient Honey", 10);

	//Create artifacts
	Item* a1 = new Artifact("Bent spoon", 10);
	Item* a2 = new Artifact("Chipped flagon", 10);
	Item* a3 = new Artifact("Idol?", 15);
	Item* a4 = new Artifact("Bone necklace", 50);
	Item* a5 = new Artifact("Small mural slab", 20);

	//KEY artifact
	Item* key = new Artifact("key", 1);

    //Create rooms
	//Construct rooms with their appropriate pointers

	//For the sake of the story, the environment is non-linear,
	//In application, the rooms are connected linearly
	
	Room* lab1 = new Lab("Lab");
	Room* e1 = new Entry("Entry");
	Room* k1 = new Kitchen("Kitchen");
	Room* d1 = new DiningHall("Dining Hall");
	Room* l2 = new Lab("Another Lab?");
	Room* lib = new Library("Library");

	//Add items to rooms
	// Lab
	lab1->addItem(&in1);
	lab1->addItem(&in2);
	lab1->addItem(&in3);
	lab1->addItem(&in4);
	lab1->addItem(&in5);
	lab1->addItem(&in6);
	lab1->addItem(&in7);
	lab1->addItem(&in8);
	lab1->addItem(&in9);
	lab1->addItem(&in10);

	//Kitchen
	k1->addItem(&h1);
	k1->addItem(&h2);
	k1->addItem(&h3);
	k1->addItem(&h4);

	//Dining Hall
	d1->addItem(&a1);
	d1->addItem(&a2);
	d1->addItem(&a3);
	d1->addItem(&a4);
	d1->addItem(&a5);

	//Lab 2
	l2->addItem(&book1);
	l2->addItem(&book2);
	l2->addItem(&book3);
	l2->addItem(&book4);
	l2->addItem(&book5);
	l2->addItem(&book6);

	//Set up room pointers
	e1->setPtrs(lab1, NULL, NULL, NULL);
	lab1->setPtrs(k1, e1, NULL, NULL);
	k1->setPtrs(d1, k1, NULL, NULL);
	d1->setPtrs(l2, k1, NULL, NULL);
	l2->setPtrs(lib, l2, NULL, NULL);
	lib->setPtrs(NULL, l2, NULL, NULL);


	//Create you
	PC* player = new PC("you!");

	//Set your location
	//Begin in the Entry
	player->setLocation(e1);
    
	storyDriver(player, e1, lab1, k1, d1, l2, lib, key);

	///////////////////////////////////
	//testing
	//////////////////////////////////

	//e1->search();
	//cout << "" << endl;

	//lab1->removeItem();
	//lab1->removeItem();

	//cout << "........." << endl;

	//k1->removeItem();
	//k1->removeItem();

	//lab1->search();
	//k1->search();
	//d1->search();
	//l2->search();

	//e1->interact();
	//cout << "........." << endl;
	//lab1->interact();
	//cout << "........." << endl;
	//k1->interact();
	//cout << "........." << endl;
	//d1->interact();
	//cout << "........." << endl;
	//cout << "lab 2 interact" << endl;
	//l2->interact2();
	//cout << "........." << endl;
	//lib->interact();

	//cout << "........." << endl;

	/*player->setLocation(lab1);
	player->collect(lab1);
	player->getInventory();

	player->dropItem();
*/
	// Testing final condition

	/*player->add(key);
	libraryDriver(lib, player);
	
	cin.ignore();*/


	//Delete all the objects
	// free all this dang memory

	//Rooms
	delete e1;
	delete lab1;
	delete k1;
	delete d1;
	delete l2;
	delete lib;

	//characters
	delete player;

	//Items
	delete book1;
	delete book2;
	delete book3;
	delete book4;
	delete book5;
	delete book6;

	delete in1;
	delete in2;
	delete in3;
	delete in4;
	delete in5;
	delete in6;
	delete in7;
	delete in8;
	delete in9;
	delete in10;

	delete h1;
	delete h2;
	delete h3;
	delete h4;

	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;

	delete key;

	//Call thanks function
	thx(); 

	return 0;

    
}

void storyDriver(PC* player, Room* e1, Room* lab1, Room* k1, Room* d1, Room* l2, Room* lib, Item* key)
{
	//Begin the story
	title();

	introText();

	//Call first room
	entryDriver(e1, player);

	// This interrupts execution and jumps to the very end
	// If a player exceeds their alloted actions in any room
	if (e1->getActions() >= 10)
	{
		return;
	}

	//Call second room
	labDriver(lab1, player);
	if (lab1->getActions() >= 10)
	{
		return;
	}

	//Call third room
	kitchenDriver(k1, player);
	if (k1->getActions() >= 10)
	{
		return;
	}

	diningDriver(d1, player);
	if (d1->getActions() >= 10)
	{
		return;
	}

	Lab2Driver(l2, player, key);
	if (l2->getActions() >= 10)
	{
		return;
	}

	libraryDriver(lib, player);

}


void title()
{
    // print title from file
    cout << "162 Final Project" << endl;
	cout << "Win condition:" << endl;
	cout << "Pick the dust option in the last room (Lab 2). Keys will fall out. Collect the keys" << endl;
}

void introText()
{
    cout << "    " << endl;
    cout << "[Press any key after each pause to continue] " << endl;
	cin.ignore();
    cout << "You are an adventurer from a distant village. " << endl;
    cout << "You have just arrived to a towering ancient ruin. " << endl;
    cout << "You are eager to enter it, and explore its depths." << endl;
    cout << "This place is legendary for the treasure that lies within" << endl;
    cout << "You long for the chance to earn your fortune, and your honor " << endl;
    cout << "    " << endl;
    
    cin.ignore();
    cout << "....." << endl;
    cout << "    " << endl;
    
    cin.ignore();
    
    cout << "If only life were really so glamorous" << endl;
	cin.ignore();
    cout << "    " << endl;
    cout << "You have spent the last several years preparing to move to the Capitol, " << endl;
    cout << "home of the finest University in the kingdom" << endl;
    cout << "You've been accepted, against all odds, to be a student in their Magic program" << endl;
    cout << "You hope to one day ascend the ranks of mages to be the Queen's personal" << endl;
    cout << "Magical Policy Advisor" << endl;
    cout << "    " << endl;
    
    cin.ignore();
	cout << "Unfortunately your parents have decided, last minute, not to help pay your tuition. " << endl;
    cout << "You've gotten scholarships for your promise as a mage, but that only covers some expenses" << endl;
	cout << "You still need to pay for 1000 gold pieces worth of books and supplies" << endl;
    cout << "There is no way a young mage such as yourself could muster that kind of" << endl;
    cout << "gold so quickly" << endl;
    cout << "    " << endl;
    cout << "...." << endl;
    cout << "Legitimately, at least" << endl;
    cout << "    " << endl;
    
    cin.ignore();
    cout << "....." << endl;
    cout << "    " << endl;

	cin.ignore();
	cout << "You have with you your trusty bag, to store ITEMS, " << endl;
	cout << "and your own magic. You're a confident mage, but would prefer not to get" << endl;
	cout << "into any altercations" << endl;

    cout << "You push the heavy stone door aside and enter the ruin" << endl; 
    
}

void entryDriver(Room* e1, PC* player)
{
	cout << "" << endl;
	cout << "" << endl;
	e1->flavorText();
	cout << "" << endl;
	cout << "" << endl;
	bool done = false;
	bool timeUp = false;

	while (done == false)
	{

	//	while (timeUp == false)
		//{
			cout << "What will you do? " << endl;
			cout << "1: Light torches" << endl;
			cout << "2: Check inventory" << endl;
			cout << "3: Go to next room" << endl;

			int input = getData(1, 3);

			switch (input)
			{
			case 1:
				// Call e1 interact function
				e1->interact();
				timeUp = e1->time();
				if (timeUp == true)
				{
					timeUpText(player);
					done = true;
				}

				//Now you can see

				cout << "What a let down. The whole place has been ransacked" << endl;
				cout << "The flames shed light on the mess that's in here, it makes you a little itchy" << endl;
				cout << "You should have known better, of course this place would have been picked clean" << endl;
				cout << "Well, you're already here, might as well poke around" << endl;
				cout << " " << endl;
				break;

			case 2:
				player->getInventory();
				cout << "" << endl;
				timeUp = e1->time();
				if (timeUp == true)
				{
					timeUpText(player);
					done = true;
				}

				break;
			case 3:
				cout << "A long hallway extends in front of you" << endl;
				cout << "Doors line either side" << endl;
				cout << "Thanks to a faded map you pulled out of a book, you have at least some idea of where you're going" << endl;
				cout << "You decide to go on to the next room" << endl;
				cout << "" << endl;
				cout << "*********************************************************************************************************" << endl;

				//Break out of loop
				done = true;
				break;
			default:
				break;

			}
		}
		

				//if (input == 1)
				//{
				//	// Call e1 interact function
				//	e1->interact();
				//	//timeUp = e1->time();

				//	//Now you can see

				//	cout << "What a let down. The whole place has been ransacked" << endl;
				//	cout << "The flames shed light on the mess that's in here, it makes you a little itchy" << endl;
				//	cout << "You should have known better, of course this place would have been picked clean" << endl;
				//	cout << "Well, you're already here, might as well poke around" << endl;
				//	cout << "A long hallway extends in front of you" << endl;
				//	cout << "Doors line either side" << endl;
				//	cout << "Thanks to a faded map you pulled out of a book, you have at least some idea of where you're going" << endl;
				//	cout << "You decide to go on to the next room" << endl;
				//	cout << "" << endl;
				//	cout << "*********************************************************************************************************" << endl;

				//	//done == false;
				//}
			//	else if (input == 2)
			//	{
			//		player->getInventory();
			//		cout << "" << endl;
			//		timeUp = e1->time();
			//	}

			//	else if (input == 3)
			//	{
			//		cout << "A long hallway extends in front of you" << endl;
			//		cout << "Doors line either side" << endl;
			//		cout << "Thanks to a faded map you pulled out of a book, you have at least some idea of where you're going" << endl;
			//		cout << "You decide to go on to the next room" << endl;
			//		cout << "" << endl;
			//		cout << "*********************************************************************************************************" << endl;
			//		done = true;
			//		timeUp = true;
			//	}

			//	else
			//	{
			//		cout << "unknown choice" << endl;
			//	}
			//}

			//if (timeUp == true)
			//{
			//	//End game
			//	timeUpText();
			//	loss(player);
			//}
		//}
}

void labDriver(Room* lab1, PC* player)
{
	cout << "" << endl;
	cout << "" << endl;
	// Call flavortext
	lab1->flavorText();

	//Update location
	player->setLocation(lab1);

	//Menu
	
	bool done = false;
	int choice;
	bool timeUp = false;
	
	while (done == false)
	{
	
		cout << "" << endl;
		cout << "" << endl;
		cout << "What will you do? " << endl;
		cout << "1: Turn off burner" << endl;
		cout << "2: Sort through alchemy supplies" << endl;
		cout << "3: Check your bag " << endl;
		cout << "4: Move on to the next room" << endl;
		cout << "" << endl;
		cout << "" << endl;

		int input = getData(1, 4);

		switch (input)
		{
		case 1:
			lab1->interact();
			cout << "" << endl;
			timeUp = lab1->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}
			done = false;
			//getActions(lab1, player);
			break;
		case 2:
			cout << "Looks like there are a few things here" << endl;
			cout << "You can store them in your bag" << endl;
			cout << "Your back is bewitched, so weight doesn't matter, too much, but" << endl;
			cout << "size still does. You can't fit too many items, 50 tops." << endl;
			cout << "" << endl;

			if (lab1->getSearched() == false)
			{
				lab1->search();

				cout << "" << endl;
				cout << "Do you want to collect these items?" << endl;
				cout << "1: Yes" << endl;
				cout << "2: No" << endl;
				cout << "" << endl;

				choice = getData(1, 2);

				if (choice == 1)
				{
					// Collect items
					player->collect(lab1);
				}

				else
				{

					break;
				}

			}

			else
			{
				cout << "Already searched here, there's nothing left" << endl;
			}
			
			cout << "" << endl;
			timeUp = lab1->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}
			
			break;
		case 3:
			player->getInventory();
			cout << "" << endl;

			timeUp = lab1->time();
			if (timeUp == true)
			{
				done = true;
				timeUpText(player);
			}


			break;
		case 4:
			cout << "You leave for the next room" << endl;
			done = true;
			break;
		}
	}

}

void kitchenDriver(Room* k1, PC* player)
{
	cout << "" << endl;
	cout << "" << endl;
	//Call flavortext
	k1->flavorText();

	//Update Location
	player->setLocation(k1);

	//Menu

	bool done = false;
	bool timeUp = false;

	while (done == false)
	{
	
		cout << "" << endl;
		cout << "" << endl;
		cout << "What will you do? " << endl;
		cout << "1: Chat" << endl;
		cout << "2: Sort through the Items here" << endl;
		cout << "3: Check your bag" << endl;
		cout << "4: Move on to the next room" << endl;
		int input = getData(1, 4);
		int choice;
		switch (input)
		{
		case 1:
			k1->interact();
			cout << "" << endl;
			timeUp = k1->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}

			break;
		case 2:

			if (k1->getSearched() == false)
			{
				k1->search();

				cout << "" << endl;
				cout << "Do you want to collect these items?" << endl;
				cout << "1: Yes" << endl;
				cout << "2: No" << endl;

				choice = getData(1, 2);

				if (choice == 1)
				{
					// Collect items
					player->collect(k1);
				}

				else
				{
					break;
				}
			}

			else
			{
				cout << "You've already searched this room!" << endl;
			}

			cout << "" << endl;
			timeUp = k1->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}
			cout << "" << endl;
			break;
		case 3:
			player->getInventory();
			cout << "" << endl;
			timeUp = k1->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}
			break;
		case 4:
			cout << "You leave for the next room" << endl;
			done = true;
			break;
		}
	}

	

}

void diningDriver(Room* d1, PC* player)
{
	//Call flavortext
	cout << "" << endl;
	cout << "" << endl;
	d1->flavorText();

	//Update Location
	player->setLocation(d1);

	//Menu

	bool done = false;
	bool timeUp = false;

	while (done == false)
	{

		cout << "" << endl;
		cout << "" << endl;
		cout << "What will you do? " << endl;
		cout << "1: Dust up the place" << endl;
		cout << "2: Search for Items" << endl;
		cout << "3: Check your bag" << endl;
		cout << "4: Move on to the next room" << endl;
		int input = getData(1, 4);
		int choice;
		switch (input)
		{
		case 1:
			d1->interact();
			cout << "" << endl;
			timeUp = d1->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}
			break;
		case 2:

			if (d1->getSearched() == false)
			{


				cout << "There are lots of Artifacts here" << endl;
				d1->search();

				cout << "" << endl;
				cout << "Do you want to collect these items?" << endl;
				cout << "1: Yes" << endl;
				cout << "2: No" << endl;

				choice = getData(1, 2);

				if (choice == 1)
				{
					// Collect items
					player->collect(d1);
				}

				else
				{
					//d1->time();
					break;
				}
			}

			else
			{
				cout << "You already searched this room!" << endl;
			}

			cout << "" << endl;
			timeUp = d1->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}

			break;
		case 3:
			player->getInventory();
			cout << "" << endl;
			timeUp = d1->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}

			break;
		case 4:
			cout << "You leave for the next room" << endl;
			done = true;
			break;
		}
	}


}

void Lab2Driver(Room* l2, PC* player, Item* key)
{
	cout << "" << endl;
	cout << "" << endl;
	//Call flavortext
	l2->flavorText2();

	//Update Location
	player->setLocation(l2);

	//Menu

	bool done = false;
	bool timeUp = false;
	
	while (done == false)
	{

		cout << "" << endl;
		cout << "" << endl;
		cout << "What will you do? " << endl;
		cout << "1: Dust up the place" << endl;
		cout << "2: Search for Items" << endl;
		cout << "3: Check your bag" << endl;
		cout << "4: Move on to the next room" << endl;
		int input = getData(1, 4);
		int choice;
		int pickUp;
		switch (input)
		{
		case 1:
			l2->interact2();
			cout << "" << endl;
			cout << "Do you want to pick the keys up?" << endl;
			cout << "1: Yes" << endl;
			cout << "2: No" << endl;
			pickUp = getData(1, 2);
			if (pickUp == 1)
			{
				//Pick up the keys
				l2->setKey();
				player->add(key);

			}
			else
			{
				break;
			}

			cout << "" << endl;
			timeUp = l2->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}

			break;
		case 2:

			if (l2->getSearched() == false)
			{


				cout << "There are lots of Books here" << endl;
				l2->search();

				cout << "" << endl;
				cout << "Do you want to collect these items?" << endl;
				cout << "1: Yes" << endl;
				cout << "2: No" << endl;

				choice = getData(1, 2);

				if (choice == 1)
				{
					// Collect items
					player->collect(l2);
				}

				else
				{
					//l2->time();
					break;
				}
			}

			else
			{
				cout << "You already searched here!" << endl;
			}

			cout << "" << endl;
			timeUp = l2->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}

			break;
		case 3:
			player->getInventory();
			cout << "" << endl;
			timeUp = l2->time();
			if (timeUp == true)
			{
				timeUpText(player);
				done = true;
			}

			break;
		case 4:
			cout << "You leave for the next room" << endl;
			done = true;
			break;
		}
	}


	

}

void libraryDriver(Room* lib, PC* player)
{
	cout << "" << endl;
	cout << "" << endl;
	//Search inventory for Key
	bool key = player->hasKey();
	if (key == true)
	{
		//Call flavortext
		lib->flavorText();
		cout << "What do you do?" << endl;
		cout << "1: talk to the dragon" << endl;

		int choice = getData(1, 1);
		if (choice == 1)
		{



			lib->interact();

			win(player);
		}

		else
		{
			cout << "unknown choice" << endl;
		}

	}
	else
	{
		cout << "You've reached the final room, but it's barred by a heavy locked door" << endl;
		cout << "You feel magic coming from it, there's no way to open it without the key" << endl;
		cout << "..." << endl;
		cin.ignore();

		// call losing flavortext?
		loss(player);
	}
	
}

void win(PC* player)
{
	//Flavortext for win
	cout << "" << endl;
	cout << "**********************" << endl;
	cout << "Congratulations, you win!"  << endl;
	cout << "In addition to a summer job, here's what you've collected:" << endl;
	player->getInventory();
	cout << "" << endl;

	thx();
}

void loss(PC* player)
{
	cout << "You suppose it's time to go home." << endl;
	cout << "You may not have enough to sell for all the gold you need, but it's better than nothing" << endl;
	cout << "" << endl;

	cout << "Here's what you collected:" << endl;
	player->getInventory();

	cout << "" << endl;

	thx();
}

void thx()
{
	cout << "" << endl;
	cout << "Thanks for playing! " << endl;
	cin.ignore();

}

void timeUpText(PC* player)
{
	cout << "You ran as fast as you could before the ruin collapsed." << endl;
	cout << "You barely made it out, but you're alive" << endl;
	cout << "That concludes this adventure, better be more careful next time" << endl;

	loss(player);
}

/************************
Helper functions
***********************/
bool validateInt(int data, int min, int max)
{
	if (data<min || data > max)
	{
		cout << "Please enter a number between " << min << " and " << max << endl;
		return false;
	}

	return true;
}

int getData(int min, int max)
{
	bool valid = false;
	int input;
	while (valid == false)
	{
		if (cin >> input)
		{
			// Validate range
			valid = validateInt(input, min, max);

		}
		else
		{
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	return input;
}

//void getActions(Room* room, PC* player)
//{
//	int act;
//	act = room->getActions();
//
//	if (act < 10)
//	{
//		//some flavortext
//		cout << "You just did something." << endl;
//		room->setActions(act++);
//		return;
//	}
//
//	else
//	{
//		timeUpText(player);
//		loss(player);
//	}
//}

