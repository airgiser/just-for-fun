#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <assert.h>
#include "cucb_string.h"

#define MAX_LEN 255

static void string_test(void)
{
	size_t pos = 0;
	char dest[MAX_LEN];
	char str[] = "This is a simple string";
	char substr[] = "simple";
	char *p = NULL;
	char delimiters[] = " ,.;:";
	
	/*memset*/
	memset(dest, 0, MAX_LEN);

	/*str_start_with*/
	/*str_end_with*/
	/*str_find_first_of*/
	/*str_find_last_of*/
	assert(str_start_with(str, "This"));
	assert(str_end_with(str, "ing"));
	assert(str_find_first_of(str, 's') == 3);
	assert(str_find_last_of(str, 's') == 17);

	/*str_find*/
	/*str_substr*/
	pos = str_find(str, substr);
	assert(pos == 10);
	str_substr(dest, str, pos, strlen(substr));
	printf("<%s> is a sub string of <%s>\n", dest, str);

	/*strcmp*/
	/*strncmp*/
	/*strcoll*/
	/*memcmp*/
	assert(strcmp(dest, substr) == 0);
	assert(strncmp(dest, substr, strlen(substr)) == 0);
	assert(strcoll(dest, substr) == 0);
	assert(strcoll("中文", "中文") == 0);
	assert(memcmp(dest, substr, strlen(substr)) == 0);


	/*strcat example*/
	strcat(dest, " is");
	strcat(dest, " not");
	strcat(dest, " easy");
	printf("%s\n", dest);

	/*strtok example*/
	p = strtok(dest, delimiters);
	while(p != NULL)
	{
		printf("[%s]\n", p);
		p = strtok(NULL, delimiters);
	}

	/*memcpy example*/
	memcpy(dest, str, strlen(str) + 1);
	printf("%s\n", dest);

	/* memmove example
	 *
	 * void *memmove(void *dest, const void *src, size_t num)
	 *
	 * copy the values of num bytes from the location pointed by src 
	 * to the memory block pointed by destination
	 */
	memmove(dest + strlen(dest), dest, strlen(dest));
	printf("%s\n", dest);

	printf("\n");
}

static void string_span_test(void)
{
	char str[] = "abcd342";
	char keys[] = "1234567890";
	int i = 0;
	char *p = NULL;

	i = strcspn(str, keys);
	printf("The first number in %s is at index %d.\n", str, i);

	p = strpbrk(str, keys);
	while(p != NULL)
	{
		printf("%c ", *p);
		p = strpbrk(p+1, keys);
	}
	printf("\n\n");
}

static void string_convert_test(void)
{
	size_t len = 0;
	size_t wlen = 0;
	size_t slen = 0;
	char str[MAX_LEN] = {0, };
	char ustr[MAX_LEN] = {0, };
	char gstr[MAX_LEN] = {0, };
	wchar_t w_str[MAX_LEN] = {0, };

#if defined(LINUX) || defined(UNIX)
	sprintf(str, "%s", "A string include chinese:中文");
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

	sprintf(str, "%s", "A string include chinese:chinese");
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
	printf("\n");
}
int main(int argc, char *argv[])
{
	string_test();
	string_span_test();
	string_convert_test();
	return 0;
}
