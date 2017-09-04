/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description:
**************************************/

#include "Item.hpp"
#include "Ingredient.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Ingredient::Ingredient(string name, int value) : Item(name, value)
{
	
}

Ingredient::~Ingredient()
{

}

void Ingredient::check()
{
	cout << this->getName() << endl;
	cout << "An ancient alchemical ingredient" << endl;
	cout << "Probably expired for its original use, but perhaps its age gives it another purpose" << endl;
	cout << "Could be valuable to collectors or alchemists" << endl;
	cout << "Value: " << this->getValue() << endl;
    
}