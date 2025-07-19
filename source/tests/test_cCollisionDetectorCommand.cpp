///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cCollisionDetectorCommand.hpp"

// gTest grouping class
class test_cCollisionDetectorCommand : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cCollisionDetectorCommand : public cCollisionDetectorCommand
  {
  public:
    // add here members for free access.
    using cCollisionDetectorCommand::cCollisionDetectorCommand; // delegate constructors
  };

};
 
TEST_F(test_cCollisionDetectorCommand, test_ctor )
{
  Test_cCollisionDetectorCommand t(nullptr,nullptr);
}

