/*!
 * Copyright (c) airfox 2012
 *
 * \brief Collects the result of test case.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_TEST_RESULT_H
#define UCB_TEST_RESULT_H

#include <vector>

namespace ucb
{
    using std::vector;

    class TestFailure;
    class TestResult
    {
    public:
        TestResult();
        virtual ~TestResult();

        virtual void AddFailure(Test *test, const string &expression,
                const string &fileName, long lineNumber);

        virtual void Report();

    protected:
        vector<TestFailure *> m_failures;

    private:
        TestResult(const TestResult &other);
        TestResult &operator=(const TestResult &other);
    };
}
#endif // UCB_TEST_RESULT_H
