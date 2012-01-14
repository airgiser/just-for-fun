/*!
 * Copyright (c) airfox 2012
 *
 * \brief Collects the result of test case.
 * \author airfox<airgis@163.com>
 */

#include "testresult.h"

TestResult::TestResult()
{
}

TestResult::~TestResult()
{
    vector::iterator iter = m_failures.begin();
    for(; iter != m_failures.end(); ++iter)
    {
        delete *iter;
    }
}

void TestResult::AddFailure(Test *test, const string &expression,
        const string &filename, long lineNumber)
{
    m_failures.push_back(new TestFailure(test, expression, 
                filename, lineNumber));
}
