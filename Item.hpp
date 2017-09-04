/********************************
Author: Sara Hovey  
Date: 6/11/17
Description:
********************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

using std::string;

class Item
{
  private:

  protected:
  std::string name;
  int value;

  public:
  Item(std::string name, int value);
  virtual ~Item();

  int getValue();
  void setValue(int value);
  std::string getName();

  virtual void check(); 
  
};

#endif