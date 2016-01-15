/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 */

#ifndef UCB_TEST_FAILURE_H
#define UCB_TEST_FAILURE_H

#include <string>

namespace ucb
{

using std::string;

class Test;

/*
 * \class TestFailure
 */
class TestFailure
{
public:
    TestFailure(Test *failedTest, const string &message,
        const string &fileName, long lineNumber);

    virtual ~TestFailure();
        
    Test *GetFailedTest();

    const char *GetMessage();
    const char *GetFileName();
    long GetLineNumber();

private:
    Test *m_failedTest;

    string m_message;
    string m_fileName;
    long m_lineNumber;
};

inline Test *TestFailure::GetFailedTest()
{
    return m_failedTest;
}

inline const char *TestFailure::GetMessage()
{
    return m_message.c_str();
}

inline const char *TestFailure::GetFileName()
{
    return m_fileName.c_str();
}

inline long TestFailure::GetLineNumber()
{
    return m_lineNumber;
}

}// namespace ucb

#endif // UCB_TEST_FAILURE_H
