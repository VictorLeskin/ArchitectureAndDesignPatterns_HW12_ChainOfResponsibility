///************************* OUTS HOMEWORK ****************************************
#ifndef ARCHITECTUREANDDESIGNPATTERNS_HW12_CHAINOFRESPONSIBILITY_HPP
#define ARCHITECTUREANDDESIGNPATTERNS_HW12_CHAINOFRESPONSIBILITY_HPP

#include "cCollisionDetectorCommand.hpp"
#include "cGameField.hpp"
#include "cGameFieldPartition.hpp"
#include <vector>

class cGame
{
public:
	cGame();

  template<typename T> T create();

  void Execute(cAllCollisionDetectorCommand&);

  void setObjects(std::vector<cObject*>& v) { objects = &v; }
  void setGameField(cGameField& gf) { gameField = &gf; }
  void setPartitions(std::vector< cGameFieldPartition*> v) { partitions = v; }

protected:

  std::vector<cObject*> *objects;
  cGameField *gameField;
  std::vector< cGameFieldPartition*> partitions;
};

template<>
cAllCollisionDetectorCommand cGame::create<cAllCollisionDetectorCommand>();

using ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility = cGame;


#endif //#ifndef ARCHITECTUREANDDESIGNPATTERNS_HW12_CHAINOFRESPONSIBILITY_HPP
