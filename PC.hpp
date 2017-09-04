/********************************
Author: Sara Hovey  

Description:
********************************/

#ifndef PC_HPP
#define PC_HPP
#include "Character.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class PC : public Character
{
  private:	
  vector<Item*> inventory;
  Room* location;
  int maxWeight;

  public:
  PC(std::string name);
  ~PC();

  Room* getRoom();
  void getInventory();
  void checkItem(Item* item);
  void collect (Room* room);
  //void checkMap();
  void dropItem(Item* item);
  //void lookAround();
  void setLocation(Room* location);
  void add(Item* item);
  bool hasKey();
 // int getWeight();
 // void move();
 
  
};

#endif