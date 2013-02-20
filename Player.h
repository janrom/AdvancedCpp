////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Player_h__
#define __Player_h__

#include <string>
#include "GameObject.h"
#include "Gold.h"
class Game;
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{

friend class SearchCommand;
friend class SaveCommand;
friend class LoadCommand;
friend class PrintPlayerSheetCommand;

private:
  Game *game;
  int gold;
public:
  Player();
  virtual ~Player();
  void SetGame( Game * game );
  void Attack( GameObject *pObject);
  void PrintSummary();
};
////////////////////////////////////////////////////////////////////////////////
#endif
