#include <stdio.h>
#include <assert.h>
#include "cucb_path.h"

#define MAX_LEN 255
static void path_test_linux(void)
{
	char fullpath[] = "/home/airgis/dev/noname.bin";
	char filename[] = "noname.bin";
	char pathname[] = "/home/airgis/dev/";
	char mainname[] = "noname";
	char str[MAX_LEN] = {0, };
	
	/*test get filename*/
	path_get_filename(str, fullpath);
	printf("FullPath: %s\n", fullpath);
	printf("FileName: %s\n", str);

	assert(strcmp(str, filename) == 0);
	path_get_filename(str, filename);
	assert(strcmp(str, filename) == 0);
	path_get_filename(str, pathname);
	assert(strcmp(str, "") == 0);

	/*test get pathname*/
	path_get_pathname(str, fullpath);
	printf("PathName: %s\n", str);

	assert(strcmp(str, pathname) == 0);
	path_get_pathname(str, filename);
	assert(strcmp(str, "") == 0);
	path_get_pathname(str, pathname);
	assert(strcmp(str, pathname) == 0);

	/*test get extension*/
	path_get_extension(str, fullpath);
	printf("Extension: %s\n", str);

	assert(strcmp(str, "bin") == 0);
	path_get_extension(str, filename);
	assert(strcmp(str, "bin") == 0);
	path_get_extension(str, pathname);
	assert(strcmp(str, "") == 0);

	/*test get mainname*/
	path_get_mainname(str, fullpath);
	printf("Mainname: %s\n", str);
	
	assert(strcmp(str, mainname) == 0);
	path_get_mainname(str, filename);
	assert(strcmp(str, mainname) == 0);
	path_get_mainname(str, pathname);
	assert(strcmp(str, "") == 0);
	path_get_mainname(str, mainname);
	assert(strcmp(str, mainname) == 0);
}

int main(int argc, char *argv[])
{
#if defined(WIN32) || defined(WINCE)
#elif defined(LINUX) || defined(UNIX)
	path_test_linux();
#endif
	return 0;
}
