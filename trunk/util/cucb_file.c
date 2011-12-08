/*!
 * \file cucb_file.c
 * \brief file utility
 *
 * \author airfox <airgis@163.com>
 */

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#elif defined(LINUX) || defined(UNIX)
#include <sys/mman.h>
#include <fcntl.h>
#endif

#include <stdlib.h>
#include "cucb_file.h"


void *file_open(const char *filename, FileAccessMode mode)
{
	switch(mode)
	{
		case FM_READ:
			return fopen(filename, "r");
		case FM_WRITE:
			return fopen(filename, "w");
		case FM_APPEND:
			return fopen(filename, "a");
		case FM_UPDATE:
			return fopen(filename, "r+");
		case FM_READ_WRITE:
			return fopen(filename, "w+");
		case FM_READ_APPEND:
			return fopen(filename, "a+");
		case FM_BINARY_READ:
			return fopen(filename, "rb");
		case FM_BINARY_WRITE:
			return fopen(filename, "wb");
		case FM_BINARY_APPEND:
			return fopen(filename, "ab");
		case FM_BINARY_UPDATE:
			return fopen(filename, "rb+");
		case FM_BINARY_READ_WRITE:
			return fopen(filename, "wb+");
		case FM_BINARY_READ_APPEND:
			return fopen(filename, "ab+");
		default:
			return NULL;
	}
}

int file_exists(const char *path)
{
#if defined(WIN32) || defined(WINCE)
	DWORD attr = GetFileAttributesA(path);
	return (attr != 0xFFFFFFFF) ? 0 : -1;
#elif defined(LINUX) || defined(UNIX)
	return access(path, F_OK);
#endif
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

long file_get_size(const char *filename)
{
	long len = 0;
	struct stat fstat;
	stat(filename, &fstat);
	len = fstat.st_size;

	return len;
}

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
	clearerr((FILE*)file_handle);
	return;
}


MappedFile *file_mapping(const char *filename)
{
	MappedFile *mapfile = (MappedFile *)calloc(1, sizeof(MappedFile));

	/* Open the file, if it exists.
	 * If the file does not exist, creates a new file.
	 */
#if defined(WINCE)
	mapfile->file_handle = CreateFileForMappingA(filename, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
#elif defined(WIN32)
	mapfile->file_handle = CreateFileA(filename, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
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
			NULL, PAGE_READWRITE, 0, 0, 0);
	if(mapfile->mapping_handle == NULL)
	{
		DWORD errID = GetLastError();
		CloseHandle(mapfile->file_handle);
		free(mapfile);
		return NULL;
	}

	mapfile->mem_addr = MapViewOfFile(mapfile->mapping_handle,
			FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if(mapfile->mem_addr == NULL)
	{
		DWORD errID = GetLastError();
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

#if defined(WIN32) || defined(WINCE)
	if(mapped_file->mapping_handle != NULL)
	{
		CloseHandle(mapped_file->mapping_handle);
	}
#endif

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
