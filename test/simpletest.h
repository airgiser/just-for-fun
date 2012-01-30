/*
 * A unit test demo.
 */
#include "testcase.h"
using namespace ucb;

class SimpleTest : public TestCase
{
public:
    string GetName() const
    {
        return "SimpleTest";
    }

protected:
    void DoTest()
    {
        TestPlus();
        TestSub();
    }

    void TestPlus()
    {
        int i = 8;
        int j = 2;
        Assert(i + j == 10);
    }

    void TestSub()
    {
        int i = 9;
        int j = 4;
        Assert(i - j == 6);
    }
};
