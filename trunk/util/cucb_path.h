/*!
 * \file cucb_path.h
 * \brief path utility
 *
 * \author airfox <airgis@163.com>
 */

#ifndef CUCB_PATH_H_
#define CUCB_PATH_H_

#include "cucb_typedef.h"

CUCB_BEGIN

/*
 * Get file name from an absolute file path.
 */
char *path_get_filename(char *filename, const char *fullpath);
char *path_get_pathname(char *pathname, const char *fullpath);
char *path_get_mainname(char *mainname, const char *filename);
char *path_get_extension(char *extension, const char *filename);

/*
 * Get current working directory
 */
char *path_get_current_dir(char *dirname, size_t size);

#if defined(WIN32) || defined(WINCE)
/*
 * Windows could't find path named like "C:\dir\", even if "C:\dir" exists,
 * this function remove all trailing backslash from the path, except 
 * the root path named like "C:\".
 */
char *path_normalize(char *path);
#endif

CUCB_END

#endif/*CUCB_PATH_H_*/
