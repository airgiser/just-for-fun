/*!
 * Copyright (c) airfox 2011
 *
 * \file ucb_path.h
 * \brief path utility
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_PATH_H
#define UCB_PATH_H

#include "typedef.h"

UCB_BEGIN

#if defined(WIN32) || defined(WINCE)
#define PATH_SEPARATOR '\\'
#elif defined(LINUX) || defined(UNIX)
#define PATH_SEPARATOR '/'
/*MAC*/
/*const char PATH_SEPARATOR = ':';*/
#else
#error 'Only Windows, Unix and Linux are supported'
#endif

/*
 * Get file name from an absolute file path.
 * Beware of buffer overflow, if the length of buffer filename
 * is not long enough. 
 */
char *path_get_filename(char *filename, const char *fullpath);
char *path_get_pathname(char *pathname, const char *fullpath);
char *path_get_mainname(char *mainname, const char *filename);
char *path_get_extension(char *extension, const char *filename);

/*
 * Get current working directory
 */
char *path_get_current_dir(char *dirname, size_t size);

/*
 * This function scans the directory, all entries collected in namelist.
 */
int path_scan_directory(const char *dirname, char ***namelist);

/*
 * If the path is a File, 0 is returned.
 * If the path is a directory, 1 is returned.
 * Otherwise, -1 is retnrned.
 */
int path_is_dir(const char *path);

#if defined(WIN32) || defined(WINCE)
/*
 * Windows could't find path named like "C:\dir\", even if "C:\dir" exists,
 * this function remove all trailing backslash from the path, except 
 * the root path named like "C:\".
 */
char *path_normalize(char *path);
#endif

UCB_END

#endif/*UCB_PATH_H*/
