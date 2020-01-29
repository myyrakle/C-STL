#include <stdio.h>
#include "include/list.h"

decl_list(IntList, int)

void print(int e)
{
    printf("%d ", e);
}

int main()
{
    IntList list = new_IntList();
    
    list.push_back(&list, 1);
    list.push_back(&list, 2);
    list.push_back(&list, 3);
    list.push_back(&list, 4);
    list.push_back(&list, 5);

    IntList_iterator it = list.begin(&list);
    //it.next(&it);
    list.erase(&list, &it);
    //list.erase(&list, &it);

    list.for_each(&list, print);
}