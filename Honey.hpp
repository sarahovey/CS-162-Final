/********************************
Author: Sara Hovey

Description:
********************************/

#ifndef HONEY_HPP
#define HONEY_HPP
#include "Character.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>

class Honey :
	public Item
{
public:
	Honey(std::string name, int value);
	~Honey();

	virtual void check();
};

#endif

