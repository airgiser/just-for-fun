/*!
 * \file cucb_path.c
 * \brief path utility
 *
 * \author airfox <airgis@163.com>
 */

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#include <direct.h>
#elif defined(LINUX) || defined(UNIX)
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#endif

#include <assert.h>
#include <string.h>
#include "cucb_string.h"
#include "cucb_path.h"

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
				0, pos);
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

char *path_get_current_dir(char *dirname, size_t size)
{
	assert(dirname != NULL);
#if defined(WIN32) || defined(WINCE)
	GetModuleFileNameA(NULL, dirname, size);
	return path_get_pathname(dirname, dirname);
#elif defined(LINUX) || defined(UNIX)
	return getcwd(dirname, size);
#endif
}

int path_is_dir(const char *path)
{
#if defined(WIN32) || defined(WINCE)
	DWORD attr = GetFileAttributesA(path);
	if(attr == 0xFFFFFFFF)
	{
		return -1;
	}
	else if(attr & FILE_ATTRIBUTE_DIRECTORY)
	{
		return 0;
	}
	else
	{
		return 1;
	}
#elif defined(LINUX) || defined(UNIX)
	struct stat st;

	if(access(path, F_OK) != 0)
	{
		return -1;
	}

	/*Input 'man 2 stat' to get mor information about stat*/
	stat(path, &st);
	if(S_ISDIR(st.st_mode))
	{
		return 0;
	}
	else
	{
		return 1;
	}
#endif
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
