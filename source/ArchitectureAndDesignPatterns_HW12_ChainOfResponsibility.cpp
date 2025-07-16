///************************* OUTS HOMEWORK ****************************************

#include "ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility.hpp"

ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility::ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility() 
{
}

template<>
cCollisionDetectorCommand ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility::create<cCollisionDetectorCommand>()
{
  cCollisionDetectorCommand cmd;
  return cmd;
}
