/********************************
Author: Sara Hovey  
Date: 5/13/17
Description:
********************************/

#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
#include <vector>
#include "Item.hpp"

using std::string;
using std::vector;

class Room
{
private:
  std::string name;


protected:
  vector <Item*> items;
  Room* forward;
  Room* backward;
  Room* left;
  Room* right;
  bool status;
  bool searched;
  int actions;

  public:
  //Room(std::string name, Room* forward, Room* backward, Room* left, Room* right);
  Room(std::string name);
  virtual ~Room();
  std::string getName();
  virtual void setPtrs(Room* f, Room* b, Room* l, Room* r);
  virtual void getItems();
  virtual void flavorText();
  virtual void flavorText2();
  virtual void interact2();
  virtual void setKey();
  virtual void interact();
  virtual void search();
  virtual void addItem(Item** item);
  virtual void removeItem();
  virtual int numItems();
  virtual bool time();
  virtual bool getSearched();
  int getActions();
  void setActions(int actions);


  virtual vector<Item*> getInventory();



  
};

#endif