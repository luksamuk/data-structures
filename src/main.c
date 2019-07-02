#include <stdio.h>

#include "list.h"
#include "stack.h"

void
print_int_list_item(void *const item) {
    int *const value = item;
    printf("%d ", *value);
}

void
square_int_list_item(void *const item) {
    int *const value = item;
    *value *= *value;
}

void
print_list(list_t *list) {
    list_map(list, print_int_list_item);
    putchar(10);
}

void
print_stack(stack_t *stack) {
    stack_map(stack, print_int_list_item);
    putchar(10);
}

int
list_test(void)
{
    int ret;
    
    int i;
    list_t *list;

    ret = 0;

    puts("*** Create list");
    list = make_list(sizeof(int));
    if(list) puts("- Ok");

    puts("*** Populate list");
    for(i = 0; i < 10; i++) {
        ret += !list_append(list, &i);
    }
    print_list(list);

    puts("*** Push 23 to top of list");
    i = 23;
    ret += !list_push(list, &i);
    print_list(list);

    puts("*** Square list items");
    list_map(list, square_int_list_item);
    print_list(list);

    puts("*** Pop from list");
    ret += !list_pop(list);
    print_list(list);

    puts("*** Remove element #3");
    ret += !list_remove_at(list, 3);
    print_list(list);

    puts("*** (f) Remove element #29");
    ret += i = list_remove_at(list, 29);
    print_list(list);
    if(!i) puts("- Ok");

    puts("*** Insert 35 at position #4");
    i = 35;
    ret += !list_insert_at(list, &i, 4);
    print_list(list);

    puts("*** (f) Insert 46 at position #99");
    i = 46;
    ret += i = list_insert_at(list, &i, 99);
    print_list(list);
    if(!i) puts("- Ok");

    puts("*** Peek at first item");
    {
        i = 0;
        const int *value = list_peek(list);
        if(value) {
            printf("%d\n", *value);
        } else i = 1;
    }
    ret += i;
    if(!i) puts("- Ok");

    puts("*** Look at item at #7");
    {
        i = 0;
        const int *value = list_item_at(list, 7);
        if(value) {
            printf("%d\n", *value);
        } else i = 1;
    }
    ret += i;
    if(!i) puts("- Ok");

    puts("*** (f) Look at item at #106");
    {
        const int *value = list_item_at(list, 106);
        if(value) {
            printf("%d\n", *value);
            i = 1;
        } else i = 0;
    }
    ret += i;
    if(!i) puts("- Ok");

    puts("*** Look at item at #9");
    {
        i = 0;
        const int *value = list_item_at(list, 9);
        if(value) {
            printf("%d\n", *value);
        } else i = 1;
    }
    ret += i;
    if(!i) puts("- Ok");

    puts("*** Dispose of list");
    ret += !list_dispose(&list);
    if(!list) puts("- Ok");

    return ret;
}

int
stack_test(void)
{
    int ret;
    int i;
    stack_t *stack;

    ret = 0;

    puts("*** Create stack");
    stack = make_stack(sizeof(int));
    if(stack) puts("- Ok");

    puts("*** Push 3 to stack");
    i = 3;
    ret += !stack_push(stack, &i);
    print_stack(stack);

    puts("*** Push sequence 0--5 to stack");
    for(i = 0; i <= 5; i++)
        ret += !stack_push(stack, &i);
    print_stack(stack);

    puts("*** Peek stack");
    {
        const int *number = stack_peek(stack);
        if(number) {
            printf("%d\n", *number);
        } else ret++;
    }

    puts("*** Pop number from stack");
    ret += !stack_pop(stack);
    print_stack(stack);

    puts("*** Dispose stack");
    stack_dispose(&stack);
    if(!stack) puts("- Ok");

    return ret;
}

int
main(void)
{
    list_test();
    stack_test();
    return 0;
}
