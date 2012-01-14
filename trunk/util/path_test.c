#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "path.h"

#define MAX_LEN 256
static void path_test(void)
{
#if defined(WIN32) || defined(WINCE)
    char fullpath[] = "D:\\dev\\prj\\noname.bin";
    char pathname[] = "D:\\dev\\prj";
#elif defined(LINUX) || defined(UNIX)
    char fullpath[] = "/home/airgis/dev/noname.bin";
    char pathname[] = "/home/airgis/dev";
#endif
    char filename[] = "noname.bin";
    char mainname[] = "noname";
    char str[MAX_LEN] = {0, };
    
    /*test get filename*/
    path_get_filename(str, fullpath);
    printf("FullPath: %s\n", fullpath);
    printf("FileName: %s\n", str);

    assert(strcmp(str, filename) == 0);
    path_get_filename(str, filename);
    assert(strcmp(str, filename) == 0);

    /*test get pathname*/
    path_get_pathname(str, fullpath);
    printf("PathName: %s\n", str);

    assert(strcmp(str, pathname) == 0);
    path_get_pathname(str, filename);
    assert(strcmp(str, "") == 0);

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
    path_get_mainname(str, mainname);
    assert(strcmp(str, mainname) == 0);
}

static void scan_dir_test(char *path)
{
    char **namelist = 0;
    int n = path_scan_directory(path, &namelist);

    while(n--)
    {
        printf("%s\n", namelist[n]);
        free(namelist[n]);
    }

    free(namelist);
}

int main(int argc, char *argv[])
{
    char path[MAX_LEN] = {0, };
    path_get_current_dir(path, MAX_LEN);
    printf("%s\n", path);
    assert(path_is_dir(path) == 0);

    path_test();

    scan_dir_test(".");
    return 0;
}
