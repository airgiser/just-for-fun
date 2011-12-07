/*!
 * \file cucb_path.c
 * \brief path utility
 *
 * \author airfox <airgis@163.com>
 */

#include <assert.h>
#include <string.h>
#include "cucb_string.h"
#include "cucb_path.h"


#if defined(WIN32) || defined(WINCE)
const char PATH_SEPARATOR = '\\';
#elif defined(LINUX) || defined(UNIX)
const char PATH_SEPARATOR = '/';
/*MAC*/
/*const char PATH_SEPARATOR = ':';*/
#else
#error 'Only Windows, MAC, Unix and Linux are supported'
#endif

char *path_get_filename(char *filename, const char *fullpath)
{
	size_t pos = 0;
	assert(filename != NULL && fullpath != NULL);

	pos = str_find_last_of(fullpath, PATH_SEPARATOR);
	if(pos == -1)
	{
		strncpy(filename, fullpath, strlen(fullpath));
	}
	else
	{
		str_substr(filename, fullpath, 
				pos + 1, strlen(fullpath) - pos - 1);
	}

	return filename;
}

char *path_get_pathname(char *pathname, const char *fullpath)
{
	size_t pos = 0;
	assert(pathname != NULL && fullpath != NULL);

	pos = str_find_last_of(fullpath, PATH_SEPARATOR);
	if(pos == -1)
	{
		pathname[0] = '\0';
	}
	else
	{
		str_substr(pathname, fullpath,
				0, pos + 1);
	}

	return pathname;
}

char *path_get_mainname(char *mainname, const char *filename)
{
	size_t pos = 0;
	assert(mainname != NULL && filename != NULL);

	path_get_filename(mainname, filename);

	pos = str_find_last_of(mainname, '.');
	if(pos != -1)
	{
		str_substr(mainname, mainname, 0, pos);
	}

	return mainname;
}

char *path_get_extension(char *extension, const char *filename)
{
	size_t pos = 0;
	size_t len = 0;
	assert(extension != NULL && filename != NULL);

	len = strlen(filename);
	pos = str_find_last_of(filename, '.');
	if(pos == -1 || pos == len - 1)
	{
		extension[0] = '\0';
	}
	else
	{
		str_substr(extension, filename, pos + 1, len - pos - 1);
	}

	return extension;
}

#if defined(WIN32) || defined(WINCE)
char *path_normalize(char *path)
{
	int i = strlen(path) - 1;
	assert(path != NULL);

	while(i > 1 && path[i] == PATH_SEPARATOR && path[i-1] != ':')
	{
		path[i] = '\0';
		i--;
	}

	return path;
}
#endif
