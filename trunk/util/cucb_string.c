#include "cucb_string.h"

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#endif

size_t mb_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
	return mbstowcs(dest, src, maximum);
}

size_t wchar_to_mb(char *dest, const wchar_t *src, size_t maximum)
{
	return wcstombs(dest, src, maximum);
}

size_t ansi_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
#if defined(WIN32) || defined(WINCE)
	// The return value of the below function includes the NULL termination characters
	int count = MultiByteToWideChar(/*CP_ACP*/936, 0, src, -1, dest, maximum);

	return count - 1;
#elif defined(LINUX) || defined(UNIX)
	return 0;
#endif
}

size_t wchar_to_ansi(char *dest, const wchar_t *src, size_t maximum)
{
#if defined(WIN32) || defined(WINCE)
	int count = WideCharToMultiByte(/*CP_ACP*/936, 0, src, -1, dest, maximum, NULL, NULL);
	return count - 1;
#elif defined(LINUX) || defined(UNIX)
	return 0;
#endif
}

size_t utf8_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
#if defined(WIN32) || defined(WINCE)
	int count = MultiByteToWideChar(CP_UTF8, 0, src, -1, dest, maximum);
	return count - 1;
#elif defined(LINUX) || defined(UNIX)
	return 0;
#endif
}

size_t wchar_to_utf8(char *dest, wchar_t *src, size_t maximum)
{
#if defined(WIN32) || defined(WINCE)
	int count = WideCharToMultiByte(CP_UTF8, 0, src, -1, dest, maximum,
			NULL, NULL);
	return count - 1;
#elif defined(LINUX) || defined(UNIX)
	return 0;
#endif
}
