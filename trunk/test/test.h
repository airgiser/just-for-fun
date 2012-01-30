/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_TEST_H
#define UCB_TEST_H

#include <string>

namespace ucb
{

using std::string;
class TestResult;

class Test
{
public:
    virtual ~Test() {}

    virtual void Run() = 0;
    virtual int GetTestCaseCount() const = 0;
    virtual string GetName() const = 0;
    virtual string ToString() const = 0;
};

}// namespace ucb

#endif // UCB_TEST_H
