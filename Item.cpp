/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description:
**************************************/

#include "Item.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Item::Item(string name, int value)
{
	this->name = name;
	this->value = value;
}

Item::~Item()
{

}


int Item::getValue()
{
	return this->value;
}

void Item::setValue(int value)
{
    this->value = value;
}

std::string Item::getName()
{
	return name;
}

void Item::check()
{
    cout << "I can't check from here!" << endl;
}