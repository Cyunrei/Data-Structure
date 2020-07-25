//
// Created by cyunrei on 7/25/20.
//

#ifndef DATA_STRUCTURE_LINKED_STACK_H
#define DATA_STRUCTURE_LINKED_STACK_H

#include <stdio.h>
#include <stdlib.h>

enum {
    true = 1, false = 0
};

typedef short int bool;


typedef int elem_datatype;

typedef struct stack_node {
    elem_datatype data;
    struct stack_node *next;
} stack_node, *linked_stack_ptr;

typedef struct {
    linked_stack_ptr top;
    int len;
} linked_stack;

/**
 * Initialize linked stack.
 * @author cyunrei
 * @data July 25 2020
 * @return {linked_stack} Linked stack after initialization.
 */

linked_stack linked_stack_init();

/**
 * Delete linked stack.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool linked_stack_del(linked_stack *stack);

/**
 * Determine whether the linked stack is empty.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @return {bool} If return is true, the linked stack is empty.
 */

bool linked_stack_empty(linked_stack *stack);

/**
 * Get linked stack length.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_list} Operated linked stack.
 * @return {int} The linked length.
 */

int linked_stack_len(linked_stack *stack);

/**
 * Get an element from the linked stack top.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @param elem {elem_datatype} The element on the linked stack top.
 * @return {bool} If return is true, the operation is successful.
 */

bool linked_stack_get_pop(linked_stack *stack, elem_datatype *elem);

/**
 * Push an element in linked stack.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @param elem {elem_datatype} The element that push in linked stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool linked_stack_push(linked_stack *stack, elem_datatype elem);

/**
 * Pop an element from the linked stack.
 * @author cyunrei
 * @data July 25 2020
 * @param stack {linked_stack} Operated linked stack.
 * @param elem {elem_datatype} The element that pop an element from the linked stack.
 * @return {bool} If return is true, the operation is successful.
 */

bool linked_stack_pop(linked_stack *stack, elem_datatype *elem);

#endif //DATA_STRUCTURE_LINKED_STACK_H
