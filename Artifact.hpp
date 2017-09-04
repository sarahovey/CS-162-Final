/********************************
Author: Sara Hovey  

Description:
********************************/

#ifndef Artifact_HPP
#define Artifact_HPP

#include "Item.hpp"
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Artifact : public Item
{
  private:
  

  public:
  Artifact(std::string name, int value);
  ~Artifact();

  virtual void check();
 
  
};

#endif