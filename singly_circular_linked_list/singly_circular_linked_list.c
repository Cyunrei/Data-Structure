//
// Created by cyunrei on 7/22/20.
//

#include "singly_circular_linked_list.h"

/**
 * Initialize singly circular linked list by head insert method.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {scl_list} singly circular linked list after initialization.
 */

scl_list scl_list_init_head(scl_list *list, const elem_datatype *array, int length) {
    scl_list new_node, tail_node;
    *list = (scl_list) malloc(sizeof(node));
    (*list)->next = NULL;
    (*list)->data = 0;
    for (int i = 0; i < length; i++) {
        new_node = (scl_list) malloc(sizeof(node));
        new_node->data = array[i];
        if (!i) tail_node = new_node;
        new_node->next = (*list)->next;
        (*list)->next = new_node;
    }
    tail_node->next = (*list)->next;
    return *list;
}

/**
 * Initialize singly circular linked list by tail insert method.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {scl_list} singly circular linked list after initialization.
 */

scl_list scl_list_init_tail(scl_list *list, const elem_datatype *array, int length) {
    scl_list new_node, dynamic_node;
    *list = (scl_list) malloc(sizeof(node));
    (*list)->next = NULL;
    (*list)->data = 0;
    dynamic_node = *list;
    for (int i = 0; i < length; i++) {
        new_node = (scl_list) malloc(sizeof(node));
        new_node->data = array[i];
        dynamic_node->next = new_node;
        dynamic_node = new_node;
    }
    new_node->next = (*list)->next;
    return *list;
}

/**
 * Delete singly circular linked list.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool scl_list_del(scl_list *list) {
    scl_list node, next_node;
    node = (*list)->next;
    while (node && node != (*list)->next) {
        next_node = node->next;
        free(node);
        node = next_node;
    }
    (*list)->next = NULL;
    return true;
}

/**
 * Insert a node of singly circular linked list by node index(Between head and tail).
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool scl_list_insert_node(scl_list *list, int index, elem_datatype elem) {
    scl_list dynamic_node, new_node;
    int i;
    for (i = 0, dynamic_node = *list; dynamic_node && i < index; i++, dynamic_node = dynamic_node->next);
    if (!dynamic_node || index > i) return false;
    new_node = (scl_list) malloc(sizeof(node));
    new_node->data = elem;
    new_node->next = dynamic_node->next;
    dynamic_node->next = new_node;
    return true;
}

/**
 * Delete a node of singly circular linked list by node index.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool scl_list_del_node(scl_list *list, int index) {
    scl_list dynamic_node, temp_node;
    int i;
    for (i = 1, dynamic_node = *list; dynamic_node && i < index; i++, dynamic_node = dynamic_node->next);
    if (!dynamic_node || index > i) return false;
    temp_node = dynamic_node->next;
    dynamic_node->next = temp_node->next;
    free(temp_node);
    return true;
}

/**
 * Traverse singly circular linked list and print node info.
 * @author cyunrei
 * @data July 22 2020
 * @param list {scl_list} Operated singly circular linked list.
 * @param traverse_count {int} Traverse count.
 */

void scl_list_traverse(scl_list *list, int traverse_count) {
    scl_list dynamic_node;
    int index;
    for (index = 1, dynamic_node = (*list)->next;
         dynamic_node && traverse_count; index++, dynamic_node = dynamic_node->next) {
        if (dynamic_node->next == (*list)->next && index != 1) traverse_count--;
        printf("node %3d | address %p | value %d\n", index, dynamic_node, dynamic_node->data);
    }
}
