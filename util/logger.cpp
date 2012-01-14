/*!
 * Copyright (c) airfox 2012
 *
 * \brief Implementation of file logger.
 * \author airfox<airgis@163.com>
 */

#include "logger.h"
#include "time.h"
#include "path.h"
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdarg>

using namespace std;
using namespace ucb;

CFileLogger::CFileLogger(const char *filename)
{
    char path[MAXPATHLEN] = {0, };
    char buf[MAXPATHLEN] = {0, };

    // Get log path.
    path_get_current_dir(path, MAXPATHLEN);
    path_append_sep(path);
    strcat(path, "logs");
    if(path_is_dir(path) != 0)
    {
        path_create_dir(path);
    }
    path_append_sep(path);
    m_logfile = path;

    // Get log file name.
    TimeInfo curTime;
    time_get_now(&curTime);
    sprintf(buf, "%s%04d%02d%02d.log", filename, 
            curTime.year, curTime.month, curTime.day);
    m_logfile += buf;

    // Open log file.
    m_loghandle = fopen(m_logfile.c_str(), "a+");
    assert(m_loghandle != NULL);
}

CFileLogger::~CFileLogger()
{
    fclose(static_cast<FILE *>(m_loghandle));
}

void CFileLogger::Log(const char *format, ...)
{
    char buf[1024];

    va_list v;
    va_start(v, format);
    vsprintf(buf, format, v);
    va_end(v);

    fwrite(buf, strlen(buf), 1, static_cast<FILE *>(m_loghandle));
    fflush(static_cast<FILE *>(m_loghandle));

    return;
}
