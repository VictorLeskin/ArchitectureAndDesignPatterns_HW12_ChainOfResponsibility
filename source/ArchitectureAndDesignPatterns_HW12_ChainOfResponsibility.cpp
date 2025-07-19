///************************* OUTS HOMEWORK ****************************************
#include "ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility.hpp"

#include <algorithm>

cGame::cGame()
{
}

void cAllCollisionDetectorCommand::Execute()
{
	game->Execute(*this);
}

void cAllCollisionDetectorCommand::append(cCollisionDetectorCommand cmd)
{
	if(collisionDectectionCommands.end() == std::find(collisionDectectionCommands.begin(), collisionDectectionCommands.end(), cmd) )
		collisionDectectionCommands.push_back(cmd);
}

template<>
cAllCollisionDetectorCommand cGame::create<cAllCollisionDetectorCommand>()
{
	return cAllCollisionDetectorCommand(this);
}

void cGame::Execute( cAllCollisionDetectorCommand &cmd)
{
  for (cObject* obj : *objects)
  {
	  for( int i = 0; i < 2; ++i)
	  {
		  cGameFieldPartition& p = *partitions[i];
		  cRNeighborhood* curr = p.RNeighborhood(obj->Position());
		  auto partitionObjects = curr->ListOfObjects();
		  if (false == cRNeighborhood::find( partitionObjects, obj))
		  {
			  for (const cObject* obj1 : partitionObjects)
			  {	
				  cCollisionDetectorCommand cmdAB(obj, obj1);
				  cmd.append(cmdAB);
			  }

			  if( cRNeighborhood* prev = p.RNeighborhood(obj) )
				prev->remove( obj );
			  curr->add(obj);
		  }
	  }
  }
}
