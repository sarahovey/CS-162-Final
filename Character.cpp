/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description:
**************************************/

#include "Character.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Character::Character(string name)
{
	this->name = name;
}

Character::~Character()
{

}


std::string Character::getName()
{
	return name;
}


/****************************
Gives information about the character
Character divulges information about
themselves
******************************/
void Character::check()
{
     cout << "I can't check from here!" << endl;
}