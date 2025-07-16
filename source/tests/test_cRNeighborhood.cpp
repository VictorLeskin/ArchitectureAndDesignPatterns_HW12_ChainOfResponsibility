///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cRNeighborhood.hpp"

// gTest grouping class
class test_cRNeighborhood : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_cRNeighborhood : public cRNeighborhood
  {
  public:
    // add here members for free access.
    using cRNeighborhood::cRNeighborhood; // delegate constructors
  };

};
 
TEST_F(test_cRNeighborhood, test_ctor )
{
  Test_cRNeighborhood t(nullptr,0,0,220);
}

