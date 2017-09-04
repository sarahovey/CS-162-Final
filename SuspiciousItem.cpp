/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description:
**************************************/

#include "Item.hpp"
#include "SuspiciousItem.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

SuspiciousItem::SuspiciousItem(string name) : SuspiciousItem(weight, value, name)
{
	
}

SuspiciousItem::~SuspiciousItem()
{

}

void SuspiciousItem::check()
{
    this->getName();
    cout << "A suspicious-looking " << this->getName() << endl;
    cout << "Maybe there's more to it" << endl;
    cout << this->getValue() << endl;
    cout << this->getWeight() << endl;
    
}