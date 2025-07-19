///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "cRNeighborhood.hpp"
#include "cObject.hpp"

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
		using cRNeighborhood::rN;
		using cRNeighborhood::lb;
		using cRNeighborhood::R;
		using cRNeighborhood::objects;
	};
};

TEST_F(test_cRNeighborhood, test_ctor)
{
	Test_cRNeighborhood t(nullptr, 0, 0, 220);

	EXPECT_EQ(nullptr, t.rN);
	EXPECT_EQ(cVector(0,0), t.lb);
	EXPECT_EQ(220, t.R);
}

TEST_F(test_cRNeighborhood, test_IsInside) 
{ 
	Test_cRNeighborhood t(nullptr, 10, 20, 100);

	EXPECT_EQ(nullptr, t.rN);
	EXPECT_EQ(cVector(10, 20), t.lb);
	EXPECT_EQ(100, t.R);

	{ cVector r(10, 20); EXPECT_EQ(true, t.IsInside(r)); }
	{ cVector r(10+99, 20); EXPECT_EQ(true, t.IsInside(r)); }
	{ cVector r(10, 20+99); EXPECT_EQ(true, t.IsInside(r)); }
	{ cVector r(10+99, 20+99); EXPECT_EQ(true, t.IsInside(r)); }
	{ cVector r(9, 20); EXPECT_EQ(false, t.IsInside(r)); }
	{ cVector r(10, 19); EXPECT_EQ(false, t.IsInside(r)); }
	{ cVector r(10 + 100, 20); EXPECT_EQ(false, t.IsInside(r)); }
	{ cVector r(10, 20 + 100); EXPECT_EQ(false, t.IsInside(r)); }
	{ cVector r(10 + 100, 20 + 100); EXPECT_EQ(false, t.IsInside(r)); }
}

TEST_F(test_cRNeighborhood, test_find) 
{ 
	cObject a("a", cVector(0, 0));
	cObject b("b", cVector(1, 1));
	cObject c("c", cVector(2, 2));

	std::vector<cObject*> objects = { &a,&b };

	EXPECT_FALSE(Test_cRNeighborhood::find(objects, &c));
	EXPECT_TRUE(Test_cRNeighborhood::find(objects, &a));
}

TEST_F(test_cRNeighborhood, test_remove) 
{ 
	Test_cRNeighborhood t(nullptr, 10, 20, 100);

	cObject a("a", cVector(0, 0));
	cObject b("b", cVector(1, 1));
	cObject c("c", cVector(2, 2));

	t.add(&a);
	t.add(&b);
	t.add(&c);

	t.remove(&a);

	EXPECT_EQ(2, t.objects.size());
	EXPECT_EQ(&b, t.objects[0]);
	EXPECT_EQ(&c, t.objects[1]);

	t.remove(&a);

	EXPECT_EQ(2, t.objects.size());
	EXPECT_EQ(&b, t.objects[0]);
	EXPECT_EQ(&c, t.objects[1]);
}

TEST_F(test_cRNeighborhood, test_add) 
{
	Test_cRNeighborhood t(nullptr, 10, 20, 100);

	cObject a("a", cVector(0, 0));
	cObject b("b", cVector(1, 1));
	cObject c("c", cVector(2, 2));

	t.add(&a);
	EXPECT_EQ(1, t.objects.size());
	EXPECT_EQ(&a, t.objects[0]);

	t.add(&b);
	EXPECT_EQ(2, t.objects.size());
	EXPECT_EQ(&a, t.objects[0]);
	EXPECT_EQ(&b, t.objects[1]);
}
