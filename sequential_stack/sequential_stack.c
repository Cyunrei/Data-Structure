//
// Created by cyunrei on 7/24/20.
//

#include "sequential_stack.h"

/**
 * Initialize sequential stack.
 * @author cyunrei
 * @data July 24 2020
 * @param stack_size {unsigned int} The size of the sequential stack after initialization.
 * @param increase_size {unsigned int} If the stack is full, increase the size on the original size.
 * @return {sq_stack} Sequential stack after initialization.
 */

sq_stack sq_stack_init(unsigned int stack_size, unsigned int increase_size) {
    sq_stack stack;
    stack.stack = malloc(sizeof(elem_datatype) * stack_size);
    if (!stack.stack) exit(1);
    stack.stack_size = stack_size;
    stack.top = -1;
    stack.increase_size = increase_size;
    return stack;
}

/**
 * Delete sequential stack.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_del(sq_stack *stack) {
    if (stack != NULL) {
        free(stack->stack);
        free(stack);
        return true;
    }
    return false;
}

/**
 * Clear sequential stack(Reset top to -1).
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */


bool sq_stack_clear(sq_stack *stack) {
    if (stack != NULL) {
        stack->top = -1;
        return true;
    }
    return false;
}

/**
 * Push an element in sequential stack.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @param elem {elem_datatype} The element that push in sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_push(sq_stack *stack, elem_datatype elem) {
    if (stack->top == stack->stack_size - 1) {
        stack->stack = realloc(stack->stack, (stack->stack_size + stack->increase_size) * sizeof(elem_datatype));
        if (!stack->stack) return false;
        stack->stack_size += stack->increase_size;
    }
    stack->stack[++stack->top] = elem;
    return true;
}

/**
 * Pop an element from the sequential stack.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @param elem {elem_datatype} The element that pop an element from the sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_pop(sq_stack *stack, elem_datatype *elem) {
    if (stack->top == -1) return false;
    *elem = stack->stack[stack->top--];
    return true;
}

/**
 * Get an element from the sequential stack top.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @param elem {elem_datatype} The element on the sequential stack top.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_get_pop(sq_stack *stack, elem_datatype *elem) {
    if (stack->top == -1)return false;
    *elem = stack->stack[stack->top];
    return true;
}

/**
 * Determine whether the sequential stack is empty.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @return {bool} If return is true, the sequential stack is empty.
 */

bool sq_stack_empty(sq_stack *stack) {
    if (stack->top == -1) return true;
    return false;
}

/**
 * Determine whether the sequential stack is full.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @return {bool} If return is true, the sequential stack is full.
 */

bool sq_stack_full(sq_stack *stack) {
    if (stack->top == stack->stack_size - 1) return true;
    return false;
}