//
// Created by cyunrei on 7/22/20.
//

#ifndef DATA_STRUCTURE_SINGLY_CIRCULAR_LINKED_LIST_H
#define DATA_STRUCTURE_SINGLY_CIRCULAR_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

/*Enumerate boolean type.*/
enum {
    true = 1, false = 0
};

typedef short int bool;   //Define boolean type.

typedef int elem_datatype;   //Define element data type.

/*Define singly circular linked list.*/
typedef struct node {
    elem_datatype data;   //Declare node data domain.
    struct node *next;   //Declare node pointer domain (Point to the next node).
} node, *scl_list;

/**
 * Initialize singly circular linked list by head insert method.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {scl_list} singly circular linked list after initialization.
 */

scl_list scl_list_init_head(scl_list *list, const elem_datatype *array, int length);

/**
 * Initialize singly circular linked list by tail insert method.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {scl_list} singly circular linked list after initialization.
 */

scl_list scl_list_init_tail(scl_list *list, const elem_datatype *array, int length);

/**
 * Delete singly circular linked list.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool scl_list_del(scl_list *list);

/**
 * Insert a node of singly circular linked list by node index(Between head and tail).
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool scl_list_insert_node(scl_list *list, int index, elem_datatype elem);

/**
 * Delete a node of singly circular linked list by node index.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool scl_list_del_node(scl_list *list, int index);

/**
 * Traverse singly circular linked list and print node info.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param traverse_count {int} Traverse count.
 */

void scl_list_traverse(scl_list *list,int traverse_count);

#endif //DATA_STRUCTURE_SINGLY_CIRCULAR_LINKED_LIST_H
