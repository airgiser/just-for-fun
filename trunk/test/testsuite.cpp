/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 * \author airfox<airgis@163.com>
 */

#include "testsuite.h"

using namespace ucb;

TestSuite::TestSuite(const string &suiteName) : m_name(suiteName)
{
}

TestSuite::~TestSuite()
{
}

void TestSuite::Run()
{
    vector<Test *>::iterator iter = m_suite.begin();
    for(; iter != m_suite.end(); ++iter)
    {
        (*iter)->Run();
    }
}

int TestSuite::GetTestCaseCount() const
{
    int count = 0;
    vector<Test *>::const_iterator iter = m_suite.begin();
    for(; iter != m_suite.end(); ++iter)
    {
        count += (*iter)->GetTestCaseCount();
    }

    return count;
}

string TestSuite::GetName() const
{
    return m_name;
}

string TestSuite::ToString() const
{
    return "Suite " + m_name;
}

void TestSuite::AddTest(Test *test)
{
    m_suite.push_back(test);
}
