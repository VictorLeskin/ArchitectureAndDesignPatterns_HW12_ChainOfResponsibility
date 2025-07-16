///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cGameFieldPartition.hpp"
#include "cGameField.hpp"

// gTest grouping class
class test_cGameFieldPartition : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cGameFieldPartition : public cGameFieldPartition
  {
  public:
    // add here members for free access.
    using cGameFieldPartition::cGameFieldPartition; // delegate constructors
  };

};
 
TEST_F(test_cGameFieldPartition, test_ctor )
{
  cGameField gameField(100, 200);
  Test_cGameFieldPartition t(gameField,10);
}

