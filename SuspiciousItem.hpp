/********************************
Author: Sara Hovey  

Description:
********************************/

#ifndef SuspiciousItem_HPP
#define SuspiciousItem_HPP
#include "Character.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class SuspiciousItem : public Item
{
  private:
  

  public:
  SuspiciousItem(std::string name);
  ~SuspiciousItem();

  virtual void check();
 
  
};
#endif