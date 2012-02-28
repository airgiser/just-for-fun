/*
 * TODO: more test case.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

static Ret print_int(void *context, void *data)
{
    printf("%d ", (int)data);
}

static void destroy_str(void *context, void *str)
{
    free(str);
}

static Ret print_str(void *context, void *str)
{
    printf("%s ", (char *)str);
}

static int cmp_str(void *context, void *str)
{
    return strcmp((char *)context, (char *)str);
}

static void test_int_slist()
{
    SList *alist = slist_create(NULL, NULL);

    int i = 0;
    for(i = 0; i < 100; i++)
    {
        slist_append(alist, (void *)i);
    }

    slist_foreach(alist, print_int, NULL);
    slist_destroy(alist);
}

static void test_str_slist()
{
    char *retstr = NULL;
    SList *strlist = slist_create(destroy_str, NULL);
    int num = 30;
    
    int i = 0;
    for(i = 0; i < num; i++)
    {
        slist_append(strlist, strdup("T"));
    }

    i = 3;
    slist_set_by_index(strlist, i, strdup("Q"));
    slist_insert_after(strlist, i, strdup("S"));
    slist_get_by_index(strlist, i, (void **)&retstr);
    assert(strcmp(retstr, "Q") == 0);
    assert(slist_get_length(strlist) == num + 1);

    slist_delete(strlist, i-1);
    slist_get_by_index(strlist, i, (void **)&retstr);
    assert(strcmp(retstr, "S") == 0);
    assert(slist_get_length(strlist) == num);

    assert(slist_find(strlist, cmp_str, "Q") == i-1);

    slist_foreach(strlist, print_str, NULL);
    slist_destroy(strlist);
}

int main(int argc, char *argv[])
{
    test_int_slist();
    printf("\n");
    test_str_slist();
    printf("\n");

    return 0;
}
