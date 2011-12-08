/*!
 * \file cucb_string.h
 * \brief string utility
 *
 * \author airfox <airgis@163.com>
 */

#ifndef CUCB_STRING_H_
#define CUCB_STRING_H_

#include "cucb_typedef.h"
#include <stdlib.h>

CUCB_BEGIN

/*!
 * \brief Copy the sub string of src to dest,
 * 	which has 'num' characters and begin with the 'start' pos of src.
 *
 * \param dest
 * 	Pointer to the destination array where the sub string to be stored
 * \param src
 * 	The C string source
 * \param start
 * 	The position at src where the sub string begin.
 * \param num
 * 	The num of characters to copyied
 *
 * \return
 * 	dest is returned
 */
char *str_substr(char *dest, const char *src, size_t start, size_t num);

/*!
 * \brief Locate first occurrence of character in string
 *
 * \prarm str
 * 	C string.
 * \param character
 * 	Character to be located.
 *
 * \return
 * 	The pos where the first occurrence of character in str
 * 	If failed, (size_t)(-1) is returned.
 */
size_t str_find_first_of(const char *str, int character);

size_t str_find_last_of(const char *str, int character);

size_t str_find_first_not_of(const char *str, int character);

size_t str_find_last_not_of(const char *str, int character);

/*
 * Left trim of unwanted characters from a C string.
 */
char *str_ltrim(char *str, char junk);

char *str_rtrim(char *str, char junk);

/*
 * Convert letters in str to lower case, if possible.
 */
char *str_to_lower(char *str);

char *str_to_upper(char *str);

/*!
 * \brief Find substring
 * \param str
 * 	C string to be scanned.
 * \param substr
 * 	C string containing the sequence of characters to match.
 *
 * \return
 * 	The start position where the first occurrence of substr in str.
 * 	If failed, (size_t)(-1) is returned.
 */
size_t str_find(const char *str, const char *substr);

/*
 * If the source string start with the start string, 1 is returned.
 * Otherwise, 0 is returned.
 */
int str_start_with(const char *source, const char *start);
int str_end_with(const char *source, const char *end);

/*!
 * \brief Convert a multibyte string to a wide-character string
 *
 * \param dest
 * 	Pointer to an array of wchar_t elements
 * 	long enough to store a wide string size characters long.
 * \param src
 * 	The multibyte character string to be interpreted.
 * \param size
 * 	Maximum number of wchar_t characters to be interpreted.
 *
 * \return
 * 	The number of characters translated, 
 * 	not including the ending null-character. 
 * 	If an invalid multibyte character is encountered,
 * 	a (size_t)(-1) value is returned.
 */
size_t mb_to_wchar(wchar_t *dest, const char *src, size_t maximum);

/*!
 * \brief Convert a wide-character string to a multibyte string
 *
 * \param dest
 * 	Pointer to an array of char elements at least maximum bytes long. 
 * \param src
 * 	The wide-character string to be translated.
 * \param maximum
 * 	Maximum number of bytes to be written to dest.
 *
 * \return
 * 	The number of bytes(not characters) translated and written to dest,
 * 	not including the ending null-character.
 * 	If an invalid multibyte character is encountered,
 * 	a -1 value is returned.
 */
size_t wchar_to_mb(char *dest, const wchar_t *src, size_t maximum);

#if defined(LINUX) || defined(UNIX)
/*!
 * \brief Convert an utf-8 string to a gb2312 string.
 *
 * \param destbuf
 * 	Pointer to an array of char elements at least maximum long.
 * \param srcbuf
 * 	the utf-8 encoding string
 * \maximum
 * 	Maximum number of bytes to be written to destbuf
 *
 * \return
 * 	//The function return the number of characters converted.
 * 	In case of error, it returns (size_t)(-1). 
 */
size_t utf8_to_gb(char *destbuf, char *srcbuf, size_t maximum);

/*!
 * \brief Convert an gb2312 string to an utf-8 string
 *
 * \param destbuf
 * 	Pointer to an array of char elements at least maximum long.
 * \param srcbuf
 * 	the gb2312 encoding string
 * \maximum
 * 	Maximum number of bytes to be written to destbuf
 *
 * \return
 * 	//The function return the number of characters converted.
 * 	In case of error, it returns (size_t)(-1). 
 */
size_t gb_to_utf8(char *destbuf, char *srcbuf, size_t maximum);
#endif

#if defined(WIN32) || defined(WINCE)
size_t ansi_to_wchar(wchar_t *dest, const char *src, size_t maximum);

size_t wchar_to_ansi(char *dest, const wchar_t *src, size_t maximum);

size_t utf8_to_wchar(wchar_t *dest, const char *src, size_t maximum);

size_t wchar_to_utf8(char *dest, wchar_t *src, size_t maximum);
#endif

CUCB_END

#endif
