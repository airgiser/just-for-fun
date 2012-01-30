/*!
 * Copyright (c) airfox 2012
 *
 * \brief Collects the result of test case.
 * \author airfox<airgis@163.com>
 */

#include "testresult.h"
#include "testfailure.h"
#include "test.h"

using namespace std;
using namespace ucb;

TestResult::TestResult(ostream *out) : m_out(out)
{
}

TestResult::~TestResult()
{
    vector<TestFailure *>::iterator iter = m_failures.begin();
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

void TestResult::ReportRunning(Test *test)
{
    *m_out<<"Running Test "<<test->GetName()<<"..."<<endl;
}

void TestResult::ReportResult()
{
    int size = m_failures.size();
    if(size == 0)
    {
        *m_out<<"OK!"<<endl;
    }
    else
    {
        vector<TestFailure *>::iterator iter = m_failures.begin();
        for(; iter != m_failures.end(); ++iter)
        {
            *m_out<<(*iter)->GetFileName()<<"("
                <<(*iter)->GetLineNumber()<<") : ";
            *m_out<<"Failure: "<<(*iter)->GetMessage()<<endl;
        }
        *m_out<<"Total: "<<size<<" failures."<<endl;
    }
}

