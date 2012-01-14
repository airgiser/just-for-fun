/*!
 * Copyright (c) airfox 2012
 *
 * \brief Write message to log file.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_LOGGER_H
#define UCB_LOGGER_H

#include "log.h"
#include <string>

namespace ucb
{

class CFileLogger : public ILogger
{
public:
    CFileLogger(const char *filename);
    ~CFileLogger();

    void Log(const char *format, ...);
private:
    std::string m_logfile;
    void *m_loghandle;
};

}// namespace

#endif // UCB_LOGGER_H
