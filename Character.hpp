/********************************
Author: Sara Hovey  
Date: 5/13/17
Description:
********************************/

#ifndef Character_HPP
#define Character_HPP
#include <string>

using std::string;

class Character
{
  private:
  std::string name;

  protected:
  /*int armor;
  int strength;*/

  public:
  Character(std::string name);
  virtual ~Character();

  /*int getArmor();
  int getStrength();*/
  std::string getName();
  //void setStrength(int strength);
  //virtual int attack(Character *opponent);
  //virtual int defend(int attack);
  //virtual void heal();
  virtual void check(); 
  
};

#endif