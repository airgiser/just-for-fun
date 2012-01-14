/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 * \author airfox<airgis@163.com>
 */

#include "testfailure.h"

TestFailure::TestFailure(Test *failedTest, const string &message,
        const string &fileName, long m_lineNumber) : 
    m_failedTest(failedTest), m_message(message),
    m_fileName(fileName), m_lineNumber(lineNumber)
{
}

TestFailure::~TestFailure()
{
}
