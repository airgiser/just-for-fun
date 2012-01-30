/*!
 * Copyright (c) airfox 2012
 *
 * \brief Collects the result of test case.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_TEST_RESULT_H
#define UCB_TEST_RESULT_H

#include <vector>
#include <iostream>

namespace ucb
{
    using std::vector;
    using std::ostream;
    using std::string;
    using std::cout;

    class Test;
    class TestFailure;
    class TestResult
    {
    public:
        TestResult(ostream *out = &cout);
        virtual ~TestResult();

        virtual void AddFailure(Test *test, const string &expression,
                const string &fileName, long lineNumber);

        virtual void ReportRunning(Test *test);
        virtual void ReportResult();

    protected:
        vector<TestFailure *> m_failures;

        ostream *m_out;
    private:
        TestResult(const TestResult &other);
        TestResult &operator=(const TestResult &other);
    };
}
#endif // UCB_TEST_RESULT_H
