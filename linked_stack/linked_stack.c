//
// Created by cyunrei on 7/25/20.
//

#include "linked_stack.h"

/**
 * Initialize linked stack.
 * @author cyunrei
 * @data July 25 2020
 * @return {linked_stack} Linked stack after initialization.
 */

linked_stack linked_stack_init() {
    linked_stack stack;
    stack.top = (linked_stack_ptr) malloc(sizeof(stack_node));
    if (!stack.top) exit(-1);
    stack.top = NULL;
    stack.len = 0;
    return stack;
}

/**
 * Determine whether the linked stack is empty.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @return {bool} If return is true, the linked stack is empty.
 */

bool linked_stack_del(linked_stack *stack) {
    linked_stack_ptr top_ptr, back_ptr;
    top_ptr = stack->top;
    while (top_ptr) {
        back_ptr = top_ptr;
        top_ptr = top_ptr->next;
        free(back_ptr);
    }
    stack->len = 0;
    return true;
}

bool linked_stack_empty(linked_stack *stack) {
    if (stack->len) return false;
    return true;
}

/**
 * Get linked stack length.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_list} Operated linked stack.
 * @return {int} The linked length.
 */

int linked_stack_len(linked_stack *stack) {
    return stack->len;
}

/**
 * Get an element from the linked stack top.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @param elem {elem_datatype} The element on the linked stack top.
 * @return {bool} If return is true, the operation is successful.
 */


bool linked_stack_get_pop(linked_stack *stack, elem_datatype *elem) {
    if (!stack->top) return false;
    *elem = stack->top->data;
    return true;
}

/**
 * Push an element in linked stack.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @param elem {elem_datatype} The element that push in linked stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool linked_stack_push(linked_stack *stack, elem_datatype elem) {
    linked_stack_ptr node_prt = malloc(sizeof(stack_node));
    node_prt->data = elem;
    node_prt->next = stack->top;
    stack->top = node_prt;
    stack->len++;
    return true;
}

/**
 * Pop an element from the linked stack.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @param elem {elem_datatype} The element that pop an element from the linked stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool linked_stack_pop(linked_stack *stack, elem_datatype *elem) {
    linked_stack_ptr ptr;
    if (!stack->len) return false;
    *elem = stack->top->data;
    ptr = stack->top;
    stack->top = stack->top->next;
    free(ptr);
    stack->len--;
    return true;
}

