/**************************************
Author: Sara Hovey
Date: 5/14/17
Description:
**************************************/

#include "Item.hpp"
#include "Honey.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


Honey::Honey(std::string name, int value) : Item(name, value)
{

}


Honey::~Honey()
{

}

void Honey::check()
{
	cout << this->getName() << endl;
	cout << "A small pot of ancient honey" << endl;
	cout << "They say honey doesn't expire but you're not sure if you really want to eat it" << endl;
	cout << "Maybe someone would buy it for some other purpose, though" << endl;
	cout << "Value: " << this->getValue() << endl;
}