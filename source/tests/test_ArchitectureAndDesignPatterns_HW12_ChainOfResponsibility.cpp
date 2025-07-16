///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility.hpp"

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
 
TEST_F(test_ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility, test_ctor )
{
  Test_ArchitectureAndDesignPatterns_HW12_ChainOfResponsibility t;
}

