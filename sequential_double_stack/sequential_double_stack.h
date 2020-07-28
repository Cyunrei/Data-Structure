//
// Created by cyunrei on 7/28/20.
//

#ifndef DATA_STRUCTURE_SEQUENTIAL_DOUBLE_STACK_H
#define DATA_STRUCTURE_SEQUENTIAL_DOUBLE_STACK_H

#include <stdlib.h>

typedef unsigned int bool;

enum {
    true = 1, false = 0
};

typedef int elem_datatype;

typedef struct {
    elem_datatype *elem;
    int top_l, top_r;
    unsigned int size;
} sqd_stack;

/**
 * Initialize sequential double stack.
 * @author cyunrei
 * @data July 28 2020
 * @param size {unsigned int} The size of the sequential double stack after initialization.
 * @return {sqd_stack} Sequential double stack after initialization.
 */

sqd_stack sqd_stack_init(unsigned int size);

/**
 * Push an element in sequential double stack.
 * @author cyunrei
 * @data July 28 2020
 * @param stack {sqd_stack} Operated sequential double stack.
 * @param is_l {bool} If is_l is true, operate left stack.
 * @param elem {elem_datatype} The element that push in sequential stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sqd_stack_push(sqd_stack *stack, bool is_l, elem_datatype elem);

/**
 * Pop an element from the sequential double stack.
 * @author cyunrei
 * @data July 28 2020
 * @param stack {sq_stack} Operated sequential double stack.
 * @param elem {elem_datatype} The element that push in sequential double stack.
 * @param elem {elem_datatype} The element that pop an element from the sequential double stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool sqd_stack_pop(sqd_stack *stack,bool is_l,elem_datatype *elem);

#endif //DATA_STRUCTURE_SEQUENTIAL_DOUBLE_STACK_H
