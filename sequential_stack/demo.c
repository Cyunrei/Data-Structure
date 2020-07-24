#include "sequential_stack.h"

int main() {
    sq_stack stack = sq_stack_init(5, 5);
    printf("stack is empty:%d\n",sq_stack_empty(&stack));
    sq_stack_push(&stack, 1);
    sq_stack_push(&stack, 2);
    sq_stack_push(&stack, 3);
    sq_stack_push(&stack, 4);
    sq_stack_push(&stack,5);
    printf("stack is full:%d\n",sq_stack_full(&stack));
    sq_stack_push(&stack,6);
    printf("stack is full:%d\n",sq_stack_full(&stack));
    elem_datatype elem;
    sq_stack_get_pop(&stack,&elem);
    printf("stack get pop:%d\n",elem);
    sq_stack_pop(&stack,&elem);
    printf("stack pop:%d\n",elem);
    sq_stack_pop(&stack,&elem);
    printf("stack pop:%d\n",elem);
    sq_stack_pop(&stack,&elem);
    printf("stack pop:%d\n",elem);
    sq_stack_clear(&stack);
    printf("stack is empty:%d\n",sq_stack_empty(&stack));
    sq_stack_del(&stack);
    return 0;
}
