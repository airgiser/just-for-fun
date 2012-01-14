/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 * \author airfox<airgis@163.com>
 */

#include "testcase.h"

TestCase::TestCase(TestResult *testResult) : m_testResult(testReslt)
{
}

TestCase::~TestCase()
{
}

int TestCase::GetTestCaseCount() const
{
    return 1;
}

void TestCase::AssertImp(bool condition, const string &expression,
                    string fileName, long lineNumber)
{
    if(!condition)
    {
        m_testResult->AddFailure(this, expression, fileName, lineNumber);
    }
}
