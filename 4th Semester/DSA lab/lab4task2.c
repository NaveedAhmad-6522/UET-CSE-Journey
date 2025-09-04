#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define FALSE 0
#define TRUE 1

typedef struct
{
    int number;
    char *string;
} ELEMENT_TYPE;

typedef struct
{
    int last;
    ELEMENT_TYPE a[MAX_LIST_SIZE];
} LIST_TYPE;

typedef int WINDOW_TYPE;

WINDOW_TYPE end(LIST_TYPE *list)
{
    return (list->last + 1);
}

WINDOW_TYPE empty(LIST_TYPE *list)
{
    list->last = -1;
    return end(list);
}

int is_empty(LIST_TYPE *list)
{
    if (list->last == -1)
        return TRUE;
    else
        return FALSE; // missing semicolon
}

WINDOW_TYPE first(LIST_TYPE *list)
{
    if (is_empty(list) == FALSE)
    {
        return 0;
    }
    else
    {
        return end(list); // missing closing curly brace
    }
}

WINDOW_TYPE next(WINDOW_TYPE w, LIST_TYPE *list)
{
    if (w == last(list))
    {
        return end(list);
    }
    else if (w == end(list))
    {
        printf("Can't find next after end of list\n");
        return end(list);
    }
    else
    {
        return (w + 1);
    }
}

WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list)
{
    if (w != first(list))
    {
        return (w - 1);
    }
    else
    {
        printf("Can't find previous before first element of list\n");
        return w;
    }
}

WINDOW_TYPE last(LIST_TYPE *list)
{
    return (list->last);
}

int main()
{

    LIST_TYPE myList;
    WINDOW_TYPE w;

    empty(&myList);
    printf("Is empty: %d\n", is_empty(&myList));

    myList.a[0].number = 10;
    myList.a[0].string = "First";
    myList.last = 0;

    w = next(0, &myList);
    printf("Next position: %d\n", w);

    w = previous(1, &myList);
    printf("Previous position: %d\n", w);
    return 0;
}
