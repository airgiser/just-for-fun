#include "cucb_file.h"
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	MappedFile *mfile = 0;
	char *mem_buf =  0;
	char buf[256] = "Hello!";
	int size = strlen(buf);
	const char *filename = "test.bin";
	void *hfile = file_open(filename, FM_WRITE);
	file_write(hfile, buf, sizeof(char), size);
	file_close(hfile);

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

	file_read(hfile, buf, sizeof(char), size);
	assert(strcmp(buf, "Cello!") == 0);

	return 0;
}
