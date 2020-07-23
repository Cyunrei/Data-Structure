//
// Created by cyunrei on 7/21/20.
//

#ifndef DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
#define DATA_STRUCTURE_DOUBLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

/*Enumerate boolean type.*/
enum {
    true = 1, false = 0
};

typedef short int bool;   //Define boolean type.

typedef int elem_datatype;   //Define element data type.

/*Define doubly linked list.*/
typedef struct dual_node {
    elem_datatype data;   //Declare node data domain.
    struct dual_node *prior;   //Declare prior node pointer domain (Point to the prior node).
    struct dual_node *next;   //Declare next node pointer domain (Point to the next node).
} dual_node, *dl_list;

/**
 * Initialize doubly linked list by head insert method.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {dl_list} Doubly linked list after initialization.
 */

dl_list dl_list_init_head(dl_list *list, const elem_datatype *array, int length);

/**
 * Initialize doubly linked list by tail insert method.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {dl_list} Doubly linked list after initialization.
 */

dl_list dl_list_init_tail(dl_list *list, const elem_datatype *array, int length);

/**
 * Traverse doubly linked list and print node info.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param reverse {bool} Reverse traverse doubly list.
 */

void dl_list_traverse(dl_list *list, bool reverse);

/**
 * Delete a node of doubly linked list.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param index {int} Target index of the node will be deleted.
 * @return {bool} If return is true,the operation is successful.
 */

bool dl_list_del_node(dl_list *list, int index);

/**
 * Insert a node element of doubly linked list(Between head and tail).
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param index {int} Target index of the node will be insert.
 * @param elem {elem_datatype} The element will be insert in doubly linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool dl_list_insert_node(dl_list *list, int index, elem_datatype elem);

/**
 * Doubly linked list sort.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param reverse {bool} Whether to sort from large to small(reverse equal true).
 */

void dl_list_sort(dl_list *list, bool reverse);

/**
 * Delete doubly linked list.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool dl_list_del(dl_list *list);

#endif //DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
