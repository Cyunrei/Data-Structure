//
// Created by cyunrei on 7/28/20.
//

#include "sequential_double_stack.h"

/**
 * Initialize sequential double stack.
 * @author cyunrei
 * @data July 28 2020
 * @param size {unsigned int} The size of the sequential double stack after initialization.
 * @return {sqd_stack} Sequential double stack after initialization.
 */

sqd_stack sqd_stack_init(unsigned int size) {
    sqd_stack stack;
    stack.top_l = -1;
    stack.top_r = (int) size;
    stack.size = size;
    stack.elem = malloc(sizeof(elem_datatype)*size);
    return stack;
}

/**
 * Push an element in sequential double stack.
 * @author cyunrei
 * @data July 28 2020
 * @param stack {sqd_stack} Operated sequential double stack.
 * @param is_l {bool} If is_l is true, operate left stack.
 * @param elem {elem_datatype} The element that push in sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sqd_stack_push(sqd_stack *stack, bool is_l, elem_datatype elem) {
    if (stack->top_l >= stack->top_r - 1) return false;
    if (is_l) {
        stack->elem[++stack->top_l] = elem;
        return true;
    } else {
        stack->elem[--stack->top_r] = elem;
        return true;
    }
}

/**
 * Pop an element from the sequential double stack.
 * @author cyunrei
 * @data July 28 2020
 * @param stack {sq_stack} Operated sequential double stack.
 * @param elem {elem_datatype} The element that push in sequential double stack.
 * @param elem {elem_datatype} The element that pop an element from the sequential double stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sqd_stack_pop(sqd_stack *stack, bool is_l, elem_datatype *elem) {
    if (is_l) {
        if (stack->top_l == -1) return false;
        *elem = stack->elem[stack->top_l--];
        return true;
    } else {
        if (stack->top_l >= stack->top_r) return false;
        *elem = stack->elem[stack->top_r++];
        return true;
    }
}

