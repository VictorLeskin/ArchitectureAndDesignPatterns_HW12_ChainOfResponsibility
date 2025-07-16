///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cVector.hpp"

// gTest grouping class
class test_cVector : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cVector : public cVector
  {
  public:
    // add here members for free access.
    using cVector::cVector; // delegate constructors
  };

};
 
TEST_F(test_cVector, test_ctor )
{
  Test_cVector t;
}

