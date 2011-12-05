#ifndef CUCB_STRING_H_
#define CUCB_STRING_H_

#include "cucb_typedef.h"
#include <stdlib.h>

CUCB_BEGIN

/*
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
 * \return size_t
 * 	The number of characters translated, 
 * 	not including the ending null-character. 
 * 	If an invalid multibyte character is encountered,
 * 	a (size_t)(-1) value is returned.
 */
size_t mb_to_wchar(wchar_t *dest, const char *src, size_t maximum);

/*
 * \brief Convert a wide-character string to a multibyte string
 *
 * \param dest
 * 	Pointer to an array of char elements at least maximum bytes long. 
 * \param src
 * 	The wide-character string to be translated.
 * \param maximum
 * 	Maximum number of bytes to be written to dest.
 *
 * \return size_t
 * 	The number of bytes(not characters) translated and written to dest,
 * 	not including the ending null-character.
 * 	If an invalid multibyte character is encountered,
 * 	a -1 value is returned.
 */
size_t wchar_to_mb(char *dest, const wchar_t *src, size_t maximum);

#if defined(LINUX) || defined(UNIX)
/*
 * \brief Convert an utf-8 string to a gb2312 string.
 *
 * \param destbuf
 * 	Pointer to an array of char elements at least maximum long.
 * \param srcbuf
 * 	the utf-8 encoding string
 * \maximum
 * 	Maximum number of bytes to be written to destbuf
 *
 * \return size_t
 * 	//The function return the number of characters converted.
 * 	In case of error, it returns (size_t)(-1). 
 */
size_t utf8_to_gb(char *destbuf, char *srcbuf, size_t maximum);

/*
 * \brief Convert an gb2312 string to an utf-8 string
 *
 * \param destbuf
 * 	Pointer to an array of char elements at least maximum long.
 * \param srcbuf
 * 	the gb2312 encoding string
 * \maximum
 * 	Maximum number of bytes to be written to destbuf
 *
 * \return size_t
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
