/*
 * TODO: more test cases.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

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

static void test_str_dlist()
{
    DList *strlist = dlist_create(destroy_str, NULL, NULL);
    char *retstr = NULL;
    int num = 10;

    int i = 0;
    for(i = 0; i < num; i++)
    {
        dlist_append(strlist, strdup("E"));
    }
    for(i = 0; i < num; i++)
    {
        dlist_preappend(strlist, strdup("S"));
    }

    i = 5;
    dlist_set_by_index(strlist, i, strdup("Q"));
    dlist_insert(strlist, i, strdup("I"));
    dlist_get_by_index(strlist, i, (void **)&retstr);
    assert(strcmp(retstr, "I") == 0);
    assert(dlist_get_length(strlist) == 2 * num + 1);
    
    dlist_delete(strlist, 1);
    dlist_delete(strlist, 0);
    assert(dlist_find(strlist, cmp_str, "Q") == i-1);

    dlist_foreach(strlist, print_str, NULL);

    dlist_destroy(strlist);
}

int main(int argc, char *argv[])
{
    test_str_dlist();
    printf("\n");

    return 0;
}
