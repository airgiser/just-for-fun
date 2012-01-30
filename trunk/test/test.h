/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_TEST_H
#define UCB_TEST_H

namespace ucb
{
    class Test
    {
    public:
        virtual ~Test() {}

        virtual void Run() = 0;
        virtual int GetTestCaseCount() const = 0;
        virtual const char *GetName()  = 0;
    };
}

#endif // UCB_TEST_H
