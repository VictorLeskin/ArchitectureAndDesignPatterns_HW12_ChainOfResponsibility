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

#include <fstream>
 
TEST_F(test_ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility, test_createCollisionDetectorCommand )
{
  Test_ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility t;

  cGameField gameField(1000, 2000);
  const int R = 500; // size of R-neighbourhood

  cGameFieldPartition partion0(gameField, R);
  cGameFieldPartition partion1(gameField, R, cVector(R/2, R/2) );

  cObject obj0("#0", cVector(0, 0));
  cObject obj1("#1", cVector(999, 1999));
  cObject obj2("#2", cVector(50, 50));
  cObject obj3("#3", cVector(99, 99));
  cObject obj4("#4", cVector(998, 1998));

  std::vector<cObject*> objects;

  objects.push_back(&obj0);
  objects.push_back(&obj1);
  objects.push_back(&obj2);
  objects.push_back(&obj3);
  objects.push_back(&obj4);

  t.setGameField(gameField);
  t.setPartitions(std::vector< cGameFieldPartition*>({ &partion0, &partion1 }));
  t.setObjects(objects);


  {
      cAllCollisionDetectorCommand cmd = t.create<cAllCollisionDetectorCommand>();
      cmd.Execute();

      const auto& cd = cmd.CollisionDectectionCommands();

      EXPECT_EQ(4, cd.size());
      EXPECT_EQ("#2", cd[0].a->Id());  EXPECT_EQ("#0", cd[0].b->Id());
      EXPECT_EQ("#3", cd[1].a->Id());  EXPECT_EQ("#0", cd[1].b->Id());
      EXPECT_EQ("#3", cd[2].a->Id());  EXPECT_EQ("#2", cd[2].b->Id());
      EXPECT_EQ("#4", cd[3].a->Id());  EXPECT_EQ("#1", cd[3].b->Id());
  }

  obj2.moveTo(cVector(997, 1997));
  obj3.moveTo(cVector(501, 501)); // it not colliding 
  {
      cAllCollisionDetectorCommand cmd = t.create<cAllCollisionDetectorCommand>();
      cmd.Execute();

      const auto& cd = cmd.CollisionDectectionCommands();

      EXPECT_EQ(2, cd.size());
      EXPECT_EQ("#2", cd[0].a->Id());  EXPECT_EQ("#1", cd[0].b->Id());
      EXPECT_EQ("#2", cd[1].a->Id());  EXPECT_EQ("#4", cd[1].b->Id());
  }
}

