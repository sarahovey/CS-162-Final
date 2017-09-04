/********************************
Author: Sara Hovey  

Description:
********************************/

#ifndef Book_HPP
#define Book_HPP

#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Book : public Item
{
  private:
  

  public:
  Book(std::string name, int value);
  ~Book();

  virtual void check();
 
  
};
#endif