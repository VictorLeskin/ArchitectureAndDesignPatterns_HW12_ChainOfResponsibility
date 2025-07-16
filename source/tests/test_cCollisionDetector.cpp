///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cCollisionDetector.hpp"

// gTest grouping class
class test_cCollisionDetector : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cCollisionDetector : public cCollisionDetector
  {
  public:
    // add here members for free access.
    using cCollisionDetector::cCollisionDetector; // delegate constructors
  };

};
 
TEST_F(test_cCollisionDetector, test_ctor )
{
  Test_cCollisionDetector t;
}

