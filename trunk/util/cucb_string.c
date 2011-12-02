#include "cucb_string.h"

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#endif

size_t wchar_to_mb(char *dest, const wchar_t *src, size_t maximum)
{
#if defined(WIN32) || defined(WINCE)
	int count = WideCharToMultiByte(/*CP_ACP*/936, 0, src, -1, dest, maximum, NULL, NULL);
	dest[count] = 0;
	return count;
#else
	return wcstombs(dest, src, maximum);
#endif
}

size_t mb_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
#if defined(WIN32) || defined(WINCE)
	int count = MultiByteToWideChar(/*CP_ACP*/936, 0, src, -1, dest, maximum);
	dest[count] = 0;
	return count;
#else
	return mbstowcs(dest, src, maximum);
#endif
}
