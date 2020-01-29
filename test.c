#include <stdio.h>
#include "include/list.h"
#include "include/forward_list.h"

decl_list(IntList, int)

decl_forward_list(For, int)

void print(int e)
{
    printf("%d ", e);
}

int main()
{
    For f = new_For();
    f.push_front(&f, 3);
    f.push_front(&f, 23);

    f.for_each(&f, print);
    // IntList list = new_IntList();
    
    // list.push_back(&list, 1);
    // list.push_back(&list, 2);
    // list.push_back(&list, 3);
    // list.push_back(&list, 4);
    // list.push_back(&list, 5);

    // IntList_iterator it = list.begin(&list);
    // IntList_iterator it2 = list.begin(&list);
    // it2.next(&it2); it2.next(&it2);

    // list.erase_range(&list, &it, &it2);
    // //list.erase(&list, &it);

    //list.for_each(&list, print);
}