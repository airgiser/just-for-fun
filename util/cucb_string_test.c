#include "cucb_string.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <assert.h>


#define MAX_LEN 255
int main(int argc, char *argv[])
{
	//setlocale
	
	char str[MAX_LEN];
	wchar_t w_str[MAX_LEN];

	sprintf(str, "%s", "hello!");
	wprintf(L"ansi:%s\n", str);

	//swprintf(w_str, MAX_LEN, L"%s", str);
	mb_to_wchar(w_str, str, MAX_LEN);
	wprintf(L"unicode:%S\n", w_str);

	//sprintf(str, "%S", w_str);
	wchar_to_mb(str, w_str, MAX_LEN);
	wprintf(L"ansi:%s\n", str);
	return 0;
}
