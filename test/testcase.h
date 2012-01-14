/*!
 * Copyright (c) airfox 2012
 *
 * \brief a simple test framework.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_TEST_CASE_H
#define UCB_TEST_CASE_H

#include "test.h"
#include <string>

namespace ucb
{
    using std::string;

    class TestResult;

    /*
     * Test Case.
     */
    class TestCase : public Test
    {
        public:
            TestCase(TestResult *testResult);
            virtual ~TestCase();

            virtual void Run() = 0;
            virtual int GetTestCaseCount() const;
        protected:
            Test(const Test &other);
            Test& operator=(const Test &other);

            void AssertImp(bool condition, const string &Expression,
                    const char *fileName, long lineNumber);
        private:
            TestResult *m_testResult;
    };

#define Assert(condition) \
    (this->AssertImp((condition), (#condition), \
                     __LINE__, __FILE__))
}
#endif// UCB_TEST_CASE_H
