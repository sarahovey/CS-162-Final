/**************************************
Author: Sara Hovey  
Date: 5/14/17
Description:
**************************************/

#include "Item.hpp"
#include "Book.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Book::Book(string name, int value) : Item(name, value)
{
	
}

Book::~Book()
{

}

void Book::check()
{
	cout << this->getName() << endl;
    cout << "A dusty old tome, in an ancient language." << endl;
	cout << "You definitely can't decipher it" << endl;
	cout << "Value: " << this->getValue() << endl;
    
}