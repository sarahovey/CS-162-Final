/********************************
Author: Sara Hovey  

Description:
********************************/

#ifndef Ingredient_HPP
#define Ingredient_HPP

#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Ingredient : public Item
{
  private:
  

  public:
  Ingredient(std::string name, int value);
  ~Ingredient();

  virtual void check();
 
  
};

#endif