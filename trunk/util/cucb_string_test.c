#include "cucb_string.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <assert.h>


#define MAX_LEN 255
int main(int argc, char *argv[])
{
	size_t len = 0;
	size_t wlen = 0;
	size_t slen = 0;
	char str[MAX_LEN] = {0, };
	char ustr[MAX_LEN] = {0, };
	char gstr[MAX_LEN] = {0, };
	wchar_t w_str[MAX_LEN] = {0, };

#if defined(LINUX) || defined(UNIX)
	sprintf(str, "%s", "hello,中文");
	printf("utf-8:%s\n", str);

	len = utf8_to_gb(gstr, str, MAX_LEN);
	assert(len != (size_t)(-1));
	printf("gb:%s\n", gstr);

	len = gb_to_utf8(ustr, gstr, MAX_LEN);
	assert(len != (size_t)(-1));
	printf("utf-8:%s\n", ustr);
#endif

#if defined(WIN32) || defined(WINCE)
	setlocale(LC_ALL, "chs");

	sprintf(str, "%s", "hello,chinese");
	printf("ansi:%s\n", str);

	//swprintf(w_str, MAX_LEN, L"%s", str);
	wlen = ansi_to_wchar(w_str, str, MAX_LEN);
	assert(wlen == wcslen(w_str));
	printf("unicode:%S\n", w_str);

	//sprintf(str, "%S", w_str);
	slen = wchar_to_ansi(str, w_str, MAX_LEN);
	assert(slen == strlen(str));
	printf("ansi:%s\n", str);

	wchar_to_utf8(str, w_str, MAX_LEN);
	utf8_to_wchar(w_str, str, MAX_LEN);
	wchar_to_ansi(str, w_str, MAX_LEN);
	printf("ansi:%s\n", str);
#endif
	return 0;
}
