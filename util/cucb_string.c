/*!
 * \file cucb_string.c
 * \brief string utility
 *
 * \author airfox <airgis@163.com>
 */

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#elif defined(LINUX) || defined(UNIX)
#include <iconv.h>
#include <string.h>
#endif

#include <assert.h>
#include "cucb_string.h"


size_t mb_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
	return mbstowcs(dest, src, maximum);
}

size_t wchar_to_mb(char *dest, const wchar_t *src, size_t maximum)
{
	return wcstombs(dest, src, maximum);
}

#if defined(LINUX) || defined(UNIX)
static size_t encoding_convert(const char *tocode, const char *fromcode, 
		char *destbuf, size_t destlen, 
		char *srcbuf, size_t srclen)
{
	size_t len = 0;
	iconv_t conv = iconv_open(tocode, fromcode);
	if(conv == NULL)
	{
		return -1;
	}

	memset(destbuf, 0, destlen);
	len = iconv(conv, &srcbuf, &srclen, &destbuf, &destlen);

	iconv_close(conv);

	return len;
}

size_t utf8_to_gb(char *destbuf, char *srcbuf, size_t maximum)
{
	size_t destlen = maximum;
	size_t srclen = strlen(srcbuf);
	return encoding_convert("euc-cn", "utf-8", 
			destbuf, destlen, srcbuf, srclen);
}

size_t gb_to_utf8(char *destbuf, char *srcbuf, size_t maximum)
{
	size_t destlen = maximum;
	size_t srclen = strlen(srcbuf);
	return encoding_convert("utf-8", "euc-cn",
			destbuf, destlen, srcbuf, srclen);
}
#endif

#if defined(WIN32) || defined(WINCE)
size_t ansi_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
	/* The return value of the below function includes
	 * the NULL termination characters
	 */
	int count = MultiByteToWideChar(/*CP_ACP*/936, 0, src, -1, dest, maximum);

	return count - 1;
}

size_t wchar_to_ansi(char *dest, const wchar_t *src, size_t maximum)
{
	int count = WideCharToMultiByte(/*CP_ACP*/936, 0, src, -1, dest, maximum, NULL, NULL);
	return count - 1;
}

size_t utf8_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
	int count = MultiByteToWideChar(CP_UTF8, 0, src, -1, dest, maximum);
	return count - 1;
}

size_t wchar_to_utf8(char *dest, wchar_t *src, size_t maximum)
{
	int count = WideCharToMultiByte(CP_UTF8, 0, src, -1, dest, maximum,
			NULL, NULL);
	return count - 1;
}
#endif
