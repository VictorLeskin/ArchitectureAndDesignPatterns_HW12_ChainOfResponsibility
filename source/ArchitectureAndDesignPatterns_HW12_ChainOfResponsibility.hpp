///************************* OUTS HOMEWORK ****************************************
#ifndef ARCHITECTUREANDDESIGNPATTERNS_HW12_CHAINOFRESPONSIBILITY_HPP
#define ARCHITECTUREANDDESIGNPATTERNS_HW12_CHAINOFRESPONSIBILITY_HPP

#include "cCollisionDetectorCommand.hpp"

class ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility
{
public:
  ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility();

  template<typename T> T create();

  
};

template<>
cCollisionDetectorCommand ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility::create<cCollisionDetectorCommand>();


#endif //#ifndef ARCHITECTUREANDDESIGNPATTERNS_HW12_CHAINOFRESPONSIBILITY_HPP
