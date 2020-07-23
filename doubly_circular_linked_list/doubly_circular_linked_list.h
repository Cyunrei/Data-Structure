//
// Created by cyunrei on 7/23/20.
//

#ifndef DATA_STRUCTURE_DOUBLY_CIRCULAR_LINKED_LIST_H
#define DATA_STRUCTURE_DOUBLY_CIRCULAR_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

/*Enumerate boolean type.*/
enum {
    true = 1, false = 0
};

typedef short int bool;   //Define boolean type.

typedef int elem_datatype;   //Define element data type.

/*Define doubly circular linked list.*/
typedef struct dual_node {
    elem_datatype data;   //Declare node data domain.
    struct dual_node *prior;   //Declare prior node pointer domain (Point to the prior node).
    struct dual_node *next;   //Declare next node pointer domain (Point to the next node).
} dual_node, *dcl_list;

/**
 * Initialize doubly circular linked list by head insert method.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated doubly circular linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {dcl_list} Doubly circular linked list after initialization.
 */

dcl_list dcl_list_init_head(dcl_list *list, const elem_datatype *array, int length);

/**
 * Initialize doubly circular linked list by tail insert method.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated doubly circular linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {dcl_list} Doubly circular linked list after initialization.
 */

dcl_list dcl_list_init_tail(dcl_list *list, const elem_datatype *array, int length);

/**
 * Delete doubly circular linked list.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated doubly circular linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool dcl_list_del(dcl_list *list);

/**
 * Insert a node of doubly circular linked list by node index(Between head and tail).
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated doubly circular linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool dcl_list_insert_node(dcl_list *list, int index, elem_datatype elem);

/**
 * Delete a node of doubly circular linked list by node index.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated doubly circular linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool dcl_list_del_node(dcl_list *list, int index);

/**
 * Traverse doubly circular linked list and print node info.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated doubly circular linked list.
 * @param traverse_count {int} Traverse count.
 * @param reverse {bool} Reverse traverse doubly circular list.
 */

void dcl_list_traverse(dcl_list *list, int traverse_count, bool reserve);


#endif //DATA_STRUCTURE_DOUBLY_CIRCULAR_LINKED_LIST_H
