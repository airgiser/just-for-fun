#include <string.h>
#include <assert.h>
#include "file.h"
#include "path.h"

#define MAX_LEN 256
int main(int argc, char *argv[])
{
    MappedFile *mfile = 0;
    char *mem_buf =  0;

    char buf[MAX_LEN] = "Hello!";
    int size = strlen(buf);
    char filename[MAX_LEN] = {0, };
    void *hfile = 0;
    
    path_get_current_dir(filename, MAX_LEN);
    sprintf(filename, "%s%c%s", filename, PATH_SEPARATOR, "test.bin");
    
    /*create file and write some characters*/
    hfile = file_open(filename, FM_WRITE);
    file_write(hfile, buf, sizeof(char), size);
    file_close(hfile);

    assert(file_exists(filename) == 0);

    /*mapping*/
    mfile = file_mapping(filename);
    if(mfile != NULL)
    {
        mem_buf = mfile->mem_addr;
        *mem_buf = 'C';
        file_unmap(mfile);
    }

    hfile = file_open(filename, FM_READ);
    file_seek(hfile, 0, FILE_SEEK_END);
    assert(size == file_tell_pos(hfile));
    file_seek(hfile, 0, FILE_SEEK_BEGIN);
    assert(size == file_get_size(filename));

    file_read(hfile, buf, sizeof(char), size);
    assert(strcmp(buf, "Cello!") == 0);

    return 0;
}
