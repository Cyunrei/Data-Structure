//
// Created by cyunrei on 7/22/20.
//

#include "singly_linked_list.h"

/**
 * Initialize singly linked list by head insert method.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {sl_list} Singly linked list after initialization.
 */

sl_list sl_list_init_head(sl_list *list, const elem_datatype *array, int length) {
    sl_list new_node;
    *list = (sl_list) malloc(sizeof(node));
    (*list)->next = NULL;
    for (int i = 0; i < length; i++) {
        new_node = (sl_list) malloc(sizeof(node));
        new_node->data = array[i];
        new_node->next = (*list)->next;
        (*list)->next = new_node;
    }
    return *list;
}

/**
 * Initialize singly linked list by tail insert method.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {sl_list} Singly linked list after initialization.
 */

sl_list sl_list_init_tail(sl_list *list, const elem_datatype *array, int length) {
    sl_list new_node, dynamic_node;
    *list = (sl_list) malloc(sizeof(node));
    (*list)->next = NULL;
    dynamic_node = *list;
    for (int i = 0; i < length; i++) {
        new_node = (sl_list) malloc(sizeof(node));
        new_node->data = array[i];
        dynamic_node->next = new_node;
        dynamic_node = new_node;
    }
    new_node->next = NULL;
    return *list;
}

/**
 * Delete singly linked list.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool sl_list_del(sl_list *list) {
    sl_list node, next_node;
    node = (*list)->next;
    while (node) {
        next_node = node->next;
        free(node);
        node = next_node;
    }
    (*list)->next = NULL;
    return true;
}

/**
 * Insert a node of singly linked list by node index(Between head and tail).
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool sl_list_insert_node(sl_list *list, int index, elem_datatype elem) {
    sl_list dynamic_node, new_node;
    int i;
    for (i = 0, dynamic_node = *list; dynamic_node && i < index; i++, dynamic_node = dynamic_node->next);
    if (!dynamic_node || index > i) return false;
    new_node = (sl_list) malloc(sizeof(node));
    new_node->data = elem;
    new_node->next = dynamic_node->next;
    dynamic_node->next = new_node;
    return true;
}

/**
 * Delete a node of singly linked list by node index.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool sl_list_del_node(sl_list *list, int index) {
    sl_list dynamic_node, temp_node;
    int i;
    for (i = 1, dynamic_node = *list; dynamic_node && i < index; i++, dynamic_node = dynamic_node->next);
    if (!dynamic_node || index > i) return false;
    temp_node = dynamic_node->next;
    dynamic_node->next = temp_node->next;
    free(temp_node);
    return true;
}

/**
 * Traverse singly linked list and print node info.
 * @author cyunrei
 * @data July 20 2020
 * @param list {sl_list} Operated singly linked list.
 */

void sl_list_traverse(sl_list *list) {
    sl_list dynamic_node;
    int index;
    for (index = 1, dynamic_node = (*list)->next; dynamic_node; index++, dynamic_node = dynamic_node->next)
        printf("node %3d | address %p | value %d\n", index, dynamic_node, dynamic_node->data);
}
