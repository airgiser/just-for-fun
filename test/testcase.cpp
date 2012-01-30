/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 * \author airfox<airgis@163.com>
 */

#include "testcase.h"
#include "testresult.h"
using namespace ucb;

TestCase::TestCase(TestResult *testResult) : m_testResult(testResult)
{
    if(m_testResult == NULL)
    {
        m_testResult = new TestResult;
    }
}

TestCase::~TestCase()
{
    delete m_testResult;
}

void TestCase::Run()
{
    m_testResult->ReportRunning(this);
    DoTest();
    m_testResult->ReportResult();
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
