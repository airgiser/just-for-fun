#include "cucb_string.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <assert.h>


#define MAX_LEN 255
int main(int argc, char *argv[])
{
	int wlen = 0;
	int slen = 0;
	char str[MAX_LEN];
	wchar_t w_str[MAX_LEN];

#if defined(WIN32) || defined(WINCE)
	setlocale(LC_ALL, "chs");
#endif

	sprintf(str, "%s", "hello,ÖÐÎÄ");
	printf("ansi:%s\n", str);

	//swprintf(w_str, MAX_LEN, L"%s", str);
	wlen = ansi_to_wchar(w_str, str, MAX_LEN);
	if(wlen < 1)
	{
		wlen = mb_to_wchar(w_str, str, MAX_LEN);
	}
	assert(wlen == wcslen(w_str));
	printf("unicode:%S\n", w_str);

	//sprintf(str, "%S", w_str);
	slen = wchar_to_ansi(str, w_str, MAX_LEN);
	if(slen < 1)
	{
		slen = wchar_to_mb(str, w_str, MAX_LEN);
	}
	assert(slen == strlen(str));
	printf("ansi:%s\n", str);

	wchar_to_utf8(str, w_str, MAX_LEN);
	utf8_to_wchar(w_str, str, MAX_LEN);
	wchar_to_ansi(str, w_str, MAX_LEN);
	printf("ansi:%s\n", str);

	return 0;
}
