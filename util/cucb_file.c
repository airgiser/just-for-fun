#include "cucb_file.h"
#include <stdlib.h>

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#elif defined(LINUX) || defined(UNIX)
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#endif

void *file_open(const char *filename, FileAccessMode mode)
{
	switch(mode)
	{
		case FILE_READ_ONLY:
			return fopen(filename, "r");
		case FILE_WRITE_ONLY:
			return fopen(filename, "w");
		case FILE_APPEND:
			return fopen(filename, "a");
		case FILE_UPDATE:
			return fopen(filename, "r+");
		case FILE_READ_WRITE:
			return fopen(filename, "w+");
		case FILE_READ_APPEND:
			return fopen(filename, "a+");
		case FILE_BINARY_READ:
			return fopen(filename, "rb");
		case FILE_BINARY_WRITE:
			return fopen(filename, "wb");
		case FILE_BINARY_APPEND:
			return fopen(filename, "ab");
		case FILE_BINARY_UPDATE:
			return fopen(filename, "rb+");
		case FILE_BINARY_READ_WRITE:
			return fopen(filename, "wb+");
		case FILE_BINARY_READ_APPEND:
			return fopen(filename, "ab+");
		default:
			return NULL;
	}
}

int file_seek(void *file_handle, long offset, FileSeekOrigin origin)
{
	return fseek((FILE*)file_handle, offset, (int)origin);
}

size_t file_read(void *file_handle, void *ptr, size_t size, size_t count)
{
	return fread(ptr, size, count, (FILE*)file_handle);
}

size_t file_write(void *file_handle, 
		const void *ptr, size_t size, size_t count)
{
	return fwrite(ptr, size, count, (FILE*)file_handle);
}

int file_flush(void *file_handle)
{
	return fflush((FILE*)file_handle);
}

long file_tell_pos(void *file_handle)
{
	return ftell((FILE*)file_handle);
}

#if defined(LINUX) || defined(UNIX)
static long file_get_size(const char *filename)
{
	long len = 0;
	struct stat fstat;
	stat(filename, &fstat);
	len = fstat.st_size;

	return len;
}
#endif

int file_close(void *file_handle)
{
	return fclose((FILE*)file_handle);
}

int file_eof(void *file_handle)
{
	return feof((FILE*)file_handle);
}

int file_error(void *file_handle)
{
	return ferror((FILE*)file_handle);
}

void file_clear_error(void *file_handle)
{
	return clearerr((FILE*)file_handle);
}


MappedFile *file_mapping(const char *filename)
{
	MappedFile *mapfile = (MappedFile *)calloc(1, sizeof(MappedFile));

	/* Open the file, if it exists.
	 * If the file does not exist, creates a new file.
	 */
#if defined(WINCE)
	mapfile->file_handle = CreateFileForMappingA(filename, GENERIC_READ|GENERIC_WRITE, FILE_SHARED_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL);
#elif defined(WIN32)
	mapfile->file_handle = CreateFileA(filename, GENERIC_READ|GENERIC_WRITE, FILE_SHARED_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL);
#elif defined(LINUX) || defined(UNIX)
	mapfile->file_handle = (void *)open(filename, O_RDWR|O_CREAT);
#endif
	if(mapfile->file_handle == NULL)
	{
		free(mapfile);
		return NULL;
	}

	/* Map the file into the address space of the process*/
#if defined(WIN32) || defined(WINCE)
	mapfile->mapping_handle = CreateFileMappingA(mapfile->file_handle,
			NULL, PAGE_READ_WRITE, 0, 0, 0);
	if(mapfile->mapping_handle == NULL)
	{
		CloseHandle(mapfile->file_handle);
		free(mapfile);
		return NULL;
	}

	mapfile->mem_addr = MapViewOfFile(mapfile->mapping_handle,
			FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if(mapfile->mem_addr == NULL)
	{
		CloseHandle(mapfile->mapping_handle);
		CloseHandle(mapfile->file_handle);
		free(mapfile);
		return NULL;
	}
#elif defined(LINUX) || defined(UNIX)
	mapfile->mem_addr = mmap(0, getpagesize(), PROT_READ|PROT_WRITE, MAP_SHARED, (int)(mapfile->file_handle), 0);	
	if(mapfile->mem_addr == NULL)
	{
		close((int)(mapfile->file_handle));
		free(mapfile);
		return NULL;
	}
#endif

	return mapfile;
}

void file_unmap(MappedFile *mapped_file)
{
	if(mapped_file->mem_addr != NULL)
	{
#if defined(WIN32) || defined(WINCE)
		UnmapViewOfFile(mapped_file->mem_addr);
#elif defined(LINUX) || defined(UNIX)
		munmap(mapped_file->mem_addr, getpagesize());
#endif
	}

	if(mapped_file->mapping_handle != NULL)
	{
#if defined(WIN32) || defined(WINCE)
		CloseHandle(mapped_file->mapping_handle);
#endif
	}

	if(mapped_file->file_handle != NULL)
	{
#if defined(WIN32) || defined(WINCE)
		CloseHandle(mapped_file->file_handle);
#elif defined(LINUX) || defined(UNIX)
		close((int)mapped_file->file_handle);
#endif
	}

	free(mapped_file);

	return;
}
