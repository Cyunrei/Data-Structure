#include "sequential_double_stack.h"
#include <stdio.h>
int main() {
    elem_datatype elem;
    sqd_stack stack = sqd_stack_init(10);
    for (int i = 1; i <= 5; i++) {
        sqd_stack_push(&stack, true, i);
    }
    for (int i = 6; i <= 11; i++) {
        sqd_stack_push(&stack, false, i);
    }
    for (int i = 1; i <= 5; i++) {
        sqd_stack_pop(&stack, true, &elem);
        printf("pop l cnt: %d elem: %d\n",i,elem);
    }
    for (int i = 1; i <= 5; i++) {
        sqd_stack_pop(&stack, false, &elem);
        printf("pop r cnt: %d elem: %d\n",i,elem);
    }
}
