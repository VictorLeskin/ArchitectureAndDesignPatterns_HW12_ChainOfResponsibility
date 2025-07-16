///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility.hpp"
#include "cGameField.hpp"
#include "cRNeighborhood.hpp"
#include "cVector.hpp"
#include "cGameFieldPartition.hpp"
#include "cObject.hpp"

// gTest grouping class
class test_ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility : public ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility
  {
  public:
    // add here members for free access.
    using ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility::ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility; // delegate constructors
  };

};
 
TEST_F(test_ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility, test_createCollisionDetectorCommand )
{
  Test_ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility t;

  cGameField gameField(1000, 2000);
  const int R = 100; // size of R-neighbourhood

  cGameFieldPartition partion0(gameField, R);
  cGameFieldPartition partion1(gameField, R, cVector(R/2, R/2) );

  std::vector<cObject> objects;

  objects.push_back(cObject("#0", cVector(0, 0)));
  objects.push_back(cObject("#1", cVector(999, 1999)));
  objects.push_back(cObject("#2", cVector(50, 50)));
  objects.push_back(cObject("#3", cVector(99, 99)));
  objects.push_back(cObject("#4", cVector(998, 1998)));


  cCollisionDetectorCommand cmd = t.create<cCollisionDetectorCommand>();
}

