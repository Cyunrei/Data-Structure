#include "linked_stack.h"

int main() {
    linked_stack stack = linked_stack_init();
    printf("stack is empty:%d\n",linked_stack_empty(&stack));
    linked_stack_push(&stack, 1);
    linked_stack_push(&stack, 2);
    linked_stack_push(&stack, 3);
    linked_stack_push(&stack, 4);
    linked_stack_push(&stack,5);
    linked_stack_push(&stack,6);
    elem_datatype elem;
    linked_stack_get_pop(&stack,&elem);
    printf("stack get pop:%d\n",elem);
    linked_stack_pop(&stack,&elem);
    printf("stack pop:%d\n",elem);
    linked_stack_pop(&stack,&elem);
    printf("stack pop:%d\n",elem);
    linked_stack_pop(&stack,&elem);
    printf("stack pop:%d\n",elem);
    printf("stack is empty:%d\n",linked_stack_empty(&stack));
    linked_stack_del(&stack);
    printf("stack len:%d\n",linked_stack_len(&stack));
    linked_stack_del(&stack);
    printf("stack len:%d\n",linked_stack_len(&stack));
    return 0;
}
