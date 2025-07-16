///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cGameField.hpp"

// gTest grouping class
class test_cGameField : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cGameField : public cGameField
  {
  public:
    // add here members for free access.
    using cGameField::cGameField; // delegate constructors
  };

};
 
TEST_F(test_cGameField, test_ctor )
{
  Test_cGameField t(100,100);
}

