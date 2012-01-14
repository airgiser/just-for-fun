/*!
 * Copyright (c) airfox 2012
 *
 * \brief Logger interface.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_LOG_H
#define UCB_LOG_H

namespace ucb
{

class ILogger
{
public:
    virtual ~ILogger() {}
    
    virtual void Log(const char *format, ...) = 0;
};

}

#endif // UCB_LOG_H
