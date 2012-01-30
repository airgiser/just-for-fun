/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_TEST_SUITE_H
#define UCB_TEST_SUITE_H

#include <vector>
#include "test.h"

namespace ucb
{

using std::vector;

class TestCase;

/*
 * \class TestSuite
 * \brief A suite of test cases.
 */
class TestSuite : public Test
{
public:
    TestSuite(const string &suiteName);
    virtual ~TestSuite();
    
    void Run();
    int GetTestCaseCount() const;
    string GetName() const;
    string ToString() const;

    void AddTest(Test *test);
protected:
    TestSuite(const TestSuite &other);
    TestSuite &operator=(const TestSuite &other);

private:
    vector<Test *> m_suite;
    string m_name;
};

}// namespace ucb

#endif // UCB_TEST_SUITE_H
