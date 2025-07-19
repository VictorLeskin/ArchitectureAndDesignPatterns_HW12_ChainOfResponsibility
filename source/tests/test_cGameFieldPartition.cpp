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

    using cGameFieldPartition::gf;
    using cGameFieldPartition::rNeighborhoods;
  };

};
 
TEST_F(test_cGameFieldPartition, test_ctor )
{
    {
        cGameField gameField(100, 150);
        Test_cGameFieldPartition t(gameField, 50);

        EXPECT_EQ(&gameField, t.gf);
        EXPECT_EQ(6, t.rNeighborhoods.size());
        EXPECT_EQ(cVector(0, 0), t.rNeighborhoods[0].LeftBottomCorner());
        EXPECT_EQ(cVector(0, 50), t.rNeighborhoods[1].LeftBottomCorner());
        EXPECT_EQ(cVector(0, 100), t.rNeighborhoods[2].LeftBottomCorner());
        EXPECT_EQ(cVector(50, 0), t.rNeighborhoods[3 + 0].LeftBottomCorner());
        EXPECT_EQ(cVector(50, 50), t.rNeighborhoods[3 + 1].LeftBottomCorner());
        EXPECT_EQ(cVector(50, 100), t.rNeighborhoods[3 + 2].LeftBottomCorner());
    }

    {
        cGameField gameField(100, 150);
        Test_cGameFieldPartition t(gameField, 50, cVector(25,25));

        EXPECT_EQ(&gameField, t.gf);
        EXPECT_EQ(12, t.rNeighborhoods.size());
        EXPECT_EQ(cVector(-25, -25), t.rNeighborhoods[0].LeftBottomCorner());
        EXPECT_EQ(cVector(-25, -25+50), t.rNeighborhoods[1].LeftBottomCorner());
        EXPECT_EQ(cVector(-25, -25+100), t.rNeighborhoods[2].LeftBottomCorner());
        EXPECT_EQ(cVector(-25, -25+150), t.rNeighborhoods[3].LeftBottomCorner());
        EXPECT_EQ(cVector(-25+50, -25), t.rNeighborhoods[4+0].LeftBottomCorner());
        EXPECT_EQ(cVector(-25+50, -25 + 50), t.rNeighborhoods[4+1].LeftBottomCorner());
        EXPECT_EQ(cVector(-25+50, -25 + 100), t.rNeighborhoods[4+2].LeftBottomCorner());
        EXPECT_EQ(cVector(-25+50, -25 + 150), t.rNeighborhoods[4+3].LeftBottomCorner());
        EXPECT_EQ(cVector(-25 +100, -25), t.rNeighborhoods[8 + 0].LeftBottomCorner());
        EXPECT_EQ(cVector(-25 +100, -25 + 50), t.rNeighborhoods[8 + 1].LeftBottomCorner());
        EXPECT_EQ(cVector(-25 +100, -25 + 100), t.rNeighborhoods[8 + 2].LeftBottomCorner());
        EXPECT_EQ(cVector(-25 +100, -25 + 150), t.rNeighborhoods[8 + 3].LeftBottomCorner());

    }

}

TEST_F(test_cGameFieldPartition, test_RNeighborhood_cVector)
{
    cGameField gameField(100, 150);
    Test_cGameFieldPartition t(gameField, 50);

    EXPECT_EQ(&gameField, t.gf);
    EXPECT_EQ(6, t.rNeighborhoods.size());
    EXPECT_EQ(cVector(0, 0), t.rNeighborhoods[0].LeftBottomCorner());
    EXPECT_EQ(cVector(0, 50), t.rNeighborhoods[1].LeftBottomCorner());
    EXPECT_EQ(cVector(0, 100), t.rNeighborhoods[2].LeftBottomCorner());
    EXPECT_EQ(cVector(50, 0), t.rNeighborhoods[3 + 0].LeftBottomCorner());
    EXPECT_EQ(cVector(50, 50), t.rNeighborhoods[3 + 1].LeftBottomCorner());
    EXPECT_EQ(cVector(50, 100), t.rNeighborhoods[3 + 2].LeftBottomCorner());

    cRNeighborhood* p = t.RNeighborhood(cVector(0 + 5, 100 + 5));

    EXPECT_EQ(&t.rNeighborhoods[2], p);
    EXPECT_EQ(nullptr, t.RNeighborhood(cVector(1000000 + 5, 100 + 5)));
}


TEST_F(test_cGameFieldPartition, test_RNeighborhood_cObject)
{
    cGameField gameField(100, 150);
    Test_cGameFieldPartition t(gameField, 50);

    cObject a("a", cVector(0, 0));
    cObject b("b", cVector(1, 1));
    cObject c("c", cVector(2, 2));
    cObject d("d", cVector(3, 3));
    cObject e("e", cVector(4, 4));
    cObject f("f", cVector(5, 5));
    cObject g("g", cVector(5, 5));

    t.rNeighborhoods[0].add(&a);
    t.rNeighborhoods[0].add(&b);
    t.rNeighborhoods[1].add(&c);
    t.rNeighborhoods[1].add(&d);
    t.rNeighborhoods[2].add(&e);
    t.rNeighborhoods[2].add(&f);

    cRNeighborhood* p = t.RNeighborhood(&f);

    EXPECT_EQ(&t.rNeighborhoods[2], p);
    EXPECT_EQ(nullptr, t.RNeighborhood(&g));
}


