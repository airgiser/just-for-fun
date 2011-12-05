/*
 * File: cucb_file.h
 * Author: airfox <airgis@163.com>
 *
 * Brief: file utility
 */

#ifndef CUCB_FILE_H_
#define CUCB_FILE_H_

#include "cucb_typedef.h"
#include <stdio.h>

CUCB_BEGIN

typedef enum _FileAccessMode
{
	/* Open a file for reading. The file must exist.*/
	FM_READ, 

	/* Create an empty file for writing.
	 * If a file with the same name already exists, its content
	 * is earsed and the file is treated as a new empty file.
	 */
	FM_WRITE,

	/* Append to a file.
	 * Writing operations append data at the end of the file. 
	 * The file is created if it does not exist.
	 */
	FM_APPEND,

	/* Open a file for update both reading and writing. 
	 * The file must exist.
	 */
	FM_UPDATE,

	/* Create an empty file for both reading and writing.
	 * If a file with the same name already exist, its content
	 * is earsed and the file is treated as a new empty file.
	 */
	FM_READ_WRITE,

	/* Open a file for reading and appending. All writing operations
	 * are performed at the end of the file, protecting the 
	 * pervious content to be overwritten. You can reposition the internal
	 * pointer to anywhere int the file for reading, but writing
	 * operations will move it back to the end of file.
	 * The file is created if it does not exist.
	 */
	FM_READ_APPEND,

	/* Open a binary file for reading. The file must exist.*/
	FM_BINARY_READ,

	/* Create an empty binary file for writing. */
	FM_BINARY_WRITE,

	/* Append to a binary file. 
	 * The file is created if it does not exist. 
	 */
	FM_BINARY_APPEND,

	/* Open a binary file for update both reading and writing. 
	 * The file must exist
	 */
	FM_BINARY_UPDATE,

	/* Create an empty binary file for both reading and writing. */
	FM_BINARY_READ_WRITE,

	/* Open a binary file for reading and appending.
	 * The file is created if it does not exist.
	 */
	FM_BINARY_READ_APPEND,
}FileAccessMode;

typedef enum _FileSeekOrigin
{
	/* Beginning of the file. */
	FILE_SEEK_BEGIN = SEEK_SET,
	/* Current position of the file pointer. */
	FILE_SEEK_CURRENT = SEEK_CUR,
	/* End of file*/
	FILE_SEEK_END = SEEK_END,
}FileSeekOrigin;

typedef struct _MappedFile
{
	void *file_handle;
#if defined(WIN32) || defined(WINCE)
	void *mapping_handle;
#endif

	void *mem_addr;
}MappedFile;

/*
 * \brief Open the file whose name is specified in the parameter filename.
 *
 * Example:
 * 	void *file_handle = file_open("filename", FILE_UPDATE);
 * 	if(file_handle != NULL)
 * 	{
 * 		...
 * 	}
 *
 * \param filename
 * 	C string containing the name of the file to be opened.
 * \param mode
 * 	File access mode
 *
 * \return int
 * 	If the file has been successfully opened, the function will return
 * 	a pointer to an object that identifies the file stream.
 * 	Otherwise, a null pointer is returned.
 */
void *file_open(const char *filename, FileAccessMode mode);

/*
 * \brief Check the file whose name is specified by filename exists or not
 *
 * \param filename
 * 	The name of the file or path.
 *
 * \return int
 * 	If the file exists, this function returns a zero value.
 * 	Otherwise, it returns nonzero value.
 */
int file_exists(const char *filename);

/*
 * \brief Reposition stream position indicator
 *
 * Example:
 * 	file_seek(file_handle, offset, FILE_SEEK_BEGIN);
 *
 * \param file_handle
 * 	Pointer to an object that identifies the file stream.
 * \param offset 
 * 	Number of bytes to offset from origin.
 * \param origin
 * 	Position from where offset is added.
 *
 * \return int
 * 	If successful, the function returns a zero value.
 * 	Otherwise, it returns nonzero value.
 */
int file_seek(void *file_handle, long offset, FileSeekOrigin origin);

/*
 * \brief Read block of data from stream
 *
 * Example:
 * 	char *buffer = (char *)malloc(sizeof(char) * count);
 * 	file_read(file_handle, buffer, sizeof(char), count);
 *
 * \param file_handle
 * 	Pointer to an object that specifies an input file stream.
 * \param ptr 
 * 	Pointer to a block of memory with a minimum size of (size*count) bytes.
 * \param size
 * 	Size in bytes of each element to be read.
 * \param count
 * 	Number of elements, each one with a size of size bytes.
 *
 * \return size_t
 * 	Return the total number of elements successfully read.
 * 	Otherwise, you can use either file_error or file_eof to check
 * 	whether an error happened or the End-of-File was reached.
 */
size_t file_read(void *file_handle, void *ptr, size_t size, size_t count);

/*
 * \brief Write block of data to stream
 *
 * Example:
 * 	fwrite(file_handle, buffer, sizeof(char), count);
 *
 * \param file_handle
 * 	Pointer to an object that specifies an output file stream.
 * \param ptr
 * 	Pointer to the array of elements to be written.
 * \param size
 * 	Size in bytes of each element to be written.
 * \param count
 * 	Number of elements, each one with a size of size bytes.
 *
 * \return size_t
 * 	Return the total number of elements successfully written.
 * 	If this number differs from the count parameter, it indicates an error.
 */
size_t file_write(void *file_handle, 
		const void *ptr, size_t size, size_t count);

/*
 * \brief Flush stream
 * 
 * \param file_handle
 * 	Pointer to an object that specifies a buffered stream.
 *
 * \return int
 * 	A zero value indicates success.
 * 	If an error occurs, EOF is returned and the error indicator is set.
 */
int file_flush(void *file_handle);

/*
 * \brief Get current position in stream.
 *
 * Example:
 * 	file_seek(file_handle, 0, FILE_SEEK_END);
 * 	size = file_tell_pos(file_handle);
 *
 * \param file_handle
 * 	Pointer to an object that identifies the stream.
 *
 * \return long int
 * 	On success, the current value of the position indicator is returned.
 * 	If an error occurs, -1L is returned, and the global variable errno
 * 	is set to indicate the error.
 */
long file_tell_pos(void *file_handle);

/*
 * \brief Get size of the file.
 *
 * \param filename
 * 	C string containing the name of the file.
 *
 * \return long
 */
long file_get_size(const char *filename);

/*
 * \brief Close file
 *
 * \param file_handle
 * 	Pointer to an object that specifies the stream to be closed.
 * 
 * \return int
 * 	If the stream is successfully closed, a zero value is returned.
 * 	On failure, EOF is returned.
 */
int file_close(void *file_handle);

/*
 * \brief Check End-of-File indicator
 *
 * Example:
 * 	while(!file_eof(file_handle))
 * 	{
 * 		...
 * 	}
 *
 * \param file_handle
 * 	Pointer to an object that identifies the stream.
 *
 * \return
 * 	A non-zero value is returned in the case that the End-of-File
 * 	indicator associated with the stream is set.
 * 	Otherwise, a zero value is returned.
 */
int file_eof(void *file_handle);

/*
 * \brief Check error indicator
 *
 * Example:
 * 	if(file_error(file_handle))
 * 	{
 * 		printf("Error: ...\n");
 * 	}
 *
 * \param file_handle
 * 	Pointer to an object that identifies the stream.
 *
 * \return int
 * 	If the error indicator associated with the stream was set,
 * 	the function returns a nonzero value.
 * 	Otherwise, it returns a zero value.
 */
int file_error(void *file_handle);

/*
 * \brief Clear error indicators. 
 * 	resets both the error and the EOF indicators of the stream.
 *
 * \param
 * 	Pointer to an object that identifies the stream.
 */
void file_clear_error(void *file_handle);

/*
 * \brief Map a file into the address space of the process.
 *
 * \param filename
 * 	C string containing the name of the file to be mapped.
 *
 * \return MappedFile
 * 	Pointer to an MappedFile object that identifies the file-mapping
 */
MappedFile *file_mapping(const char *filename);

void file_unmap(MappedFile *mapped_file);

CUCB_END

#endif
