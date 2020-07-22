//
// Created by cyunrei on 7/20/20.
//

#ifndef DATA_STRUCTURE_SINGLY_LINKED_LIST_H
#define DATA_STRUCTURE_SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

/*Enumerate boolean type.*/
enum {
    true = 1, false = 0
};

typedef short int bool;   //Define boolean type.

typedef int elem_datatype;   //Define element data type.

/*Define singly linked list.*/
typedef struct node {
    elem_datatype data;   //Declare node data domain.
    struct node *next;   //Declare node pointer domain (Point to the next node).
} node, *sl_list;

/**
 * Initialize singly linked list by head insert method.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {sl_list} Singly linked list after initialization.
 */

sl_list sl_list_init_head(sl_list *list, const elem_datatype *array, int length);

/**
 * Initialize singly linked list by tail insert method.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {sl_list} Singly linked list after initialization.
 */

sl_list sl_list_init_tail(sl_list *list, const elem_datatype *array, int length);

/**
 * Delete singly linked list.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool sl_list_del(sl_list *list);

/**
 * Insert a node of singly linked list by node index(Between head and tail).
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool sl_list_insert_node(sl_list *list, int index, elem_datatype elem);

/**
 * Delete a node of singly linked list by node index.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool sl_list_del_node(sl_list *list, int index);

/**
 * Traverse singly linked list and print node info.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 */

void sl_list_traverse(sl_list *list);

#endif //DATA_STRUCTURE_SINGLY_LINKED_LIST_H
