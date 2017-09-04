/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description:
**************************************/

#include "Item.hpp"
#include "Artifact.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Artifact::Artifact(string name, int value) : Item(name, value)
{
	
}

Artifact::~Artifact()
{

}

void Artifact::check()
{
	cout << this->getName() << endl;
    cout << "An ancient artifact. It's covered in dust." << endl;
	cout << "No telling what it's supposed to be." << endl;
	cout << "Maybe one of the anthropologists in the Capitol would know?" << endl;
	cout << "Value: " << this->getValue() << endl;
}