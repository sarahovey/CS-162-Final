/********************************
Author: Sara Hovey  

Description:
********************************/

#ifndef ENTRY_HPP
#define ENTRY_HPP
#include "Character.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Entry : public Room
{
  private:

  public:
  Entry(std::string name);
  ~Entry();

  virtual void check();
  virtual void lookAround(Room* location);
  virtual void flavorText();
  virtual void menu();
  virtual void interact();
  virtual void setPtrs(Room* f, Room* b, Room* l, Room* r);
  virtual bool time();
  
 
  
};

#endif