//
// Created by cyunrei on 7/24/20.
//

#ifndef DATA_STRUCTURE_SEQUENTIAL_STACK_H
#define DATA_STRUCTURE_SEQUENTIAL_STACK_H

#include <stdio.h>
#include <stdlib.h>

enum {
    true = 1, false = 0
};

typedef short int bool;

typedef int elem_datatype;

typedef struct {
    elem_datatype *stack;
    int top;
    unsigned int stack_size;
    unsigned int increase_size;
} sq_stack;

/**
 * Initialize sequential stack.
 * @author cyunrei
 * @data July 24 2020
 * @param stack_size {unsigned int} The size of the sequential stack after initialization.
 * @param increase_size {unsigned int} If the stack is full, increase the size on the original size.
 * @return {sq_stack} Sequential stack after initialization.
 */

sq_stack sq_stack_init(unsigned int stack_size, unsigned int increase_size);

/**
 * Delete sequential stack.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_del(sq_stack *stack);

/**
 * Clear sequential stack(Reset top to -1).
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_clear(sq_stack *stack);

/**
 * Push an element in the sequential stack.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @param elem {elem_datatype} The element that push in sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_push(sq_stack *stack, elem_datatype elem);

/**
 * Pop an element from the sequential stack.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @param elem {elem_datatype} The element that pop an element from the sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_pop(sq_stack *stack, elem_datatype *elem);

/**
 * Get an element from the sequential stack top.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @param elem {elem_datatype} The element on the sequential stack top.
 * @return {bool} If return is true, the operation is successful.
 */

bool sq_stack_get_pop(sq_stack *stack, elem_datatype *elem);

/**
 * Determine whether the sequential stack is empty.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @return {bool} If return is true, the sequential stack is empty.
 */

bool sq_stack_empty(sq_stack *stack);

/**
 * Determine whether the sequential stack is full.
 * @author cyunrei
 * @data July 24 2020
 * @param stack {sq_stack} Operated sequential stack.
 * @return {bool} If return is true, the sequential stack is full.
 */

bool sq_stack_full(sq_stack *stack);

#endif //DATA_STRUCTURE_SEQUENTIAL_STACK_H
