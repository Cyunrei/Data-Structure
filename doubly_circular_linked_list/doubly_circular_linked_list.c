//
// Created by cyunrei on 7/23/20.
//

#include "doubly_circular_linked_list.h"

/**
 * Initialize singly circular linked list by head insert method.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated singly circular linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {dcl_list} singly circular linked list after initialization.
 */

dcl_list dcl_list_init_head(dcl_list *list, const elem_datatype *array, int length) {
    dcl_list new_node, tail_node;
    *list = (dcl_list) malloc(sizeof(dual_node));
    (*list)->prior = NULL;
    (*list)->next = NULL;
    for (int i = 0; i < length; i++) {
        new_node = (dcl_list) malloc(sizeof(dual_node));
        new_node->data = array[i];
        new_node->next = (*list)->next;
        if (!i) tail_node = new_node;
        if ((*list)->next != NULL) (*list)->next->prior = new_node;
        (*list)->next = new_node;
        new_node->prior = *list;
    }
    new_node->prior = tail_node;
    tail_node->next = (*list)->next;
    tail_node->prior = new_node->prior->prior;
    return *list;
}

/**
 * Initialize singly circular linked list by tail insert method.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated singly circular linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {dcl_list} singly circular linked list after initialization.
 */

dcl_list dcl_list_init_tail(dcl_list *list, const elem_datatype *array, int length) {
    *list = (dcl_list) malloc(sizeof(dual_node));
    (*list)->prior = NULL;
    (*list)->next = NULL;
    int i;
    dcl_list new_node, dynamic_node, head_node;
    for (i = 0, dynamic_node = (*list); i < length; i++, dynamic_node->next = new_node, dynamic_node = new_node) {
        new_node = (dcl_list) malloc(sizeof(dual_node));
        if (!i) head_node = new_node;
        new_node->data = array[i];
        new_node->prior = dynamic_node;
    }
    new_node->next = head_node;
    head_node->prior = new_node;
    return *list;
}

/**
 * Delete singly circular linked list.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated singly circular linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool dcl_list_del(dcl_list *list) {
    dcl_list node, next_node;
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
 * @data July 23 2020
 * @param list {dcl_list} Operated singly circular linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool dcl_list_insert_node(dcl_list *list, int index, elem_datatype elem) {
    dcl_list dynamic_node, new_node;
    int i;
    for (i = 1, dynamic_node = *list; dynamic_node && i < index; i++, dynamic_node = dynamic_node->next);
    if (!dynamic_node || index > i) return false;
    new_node = (dcl_list) malloc(sizeof(dual_node));
    new_node->data = elem;
    new_node->prior = dynamic_node;
    new_node->next = dynamic_node->next;
    dynamic_node->next = new_node;
    new_node->next->prior = new_node;
    return true;
}

/**
 * Delete a node of singly circular linked list by node index.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated singly circular linked list.
 * @param index {int} Target node index(Begin from 1).
 * @return {bool} If return is true,the operation is successful.
 */

bool dcl_list_del_node(dcl_list *list, int index) {
    dcl_list dynamic_node, temp_node;
    int i;
    for (i = 1, dynamic_node = *list; dynamic_node && i < index; i++, dynamic_node = dynamic_node->next);
    if (!dynamic_node || index > i) return false;
    temp_node = dynamic_node->next;
    dynamic_node->next = temp_node->next;
    if (temp_node->next != NULL) temp_node->next->prior = dynamic_node;
    free(temp_node);
    return true;
}

/**
 * Traverse singly circular linked list and print node info.
 * @author cyunrei
 * @data July 23 2020
 * @param list {dcl_list} Operated singly circular linked list.
 * @param traverse_count {int} Traverse count.
 * @param reverse {bool} Reverse traverse doubly circular list.
 */

void dcl_list_traverse(dcl_list *list, int traverse_count, bool reverse) {
    dcl_list dynamic_node;
    int index;
    if (!reverse) {
        for (index = 1, dynamic_node = (*list)->next;
             dynamic_node && traverse_count; dynamic_node = dynamic_node->next, index++) {
            if (dynamic_node->next == (*list)->next) traverse_count--;
            printf("node %3d | address %p | prior %3d | value %3d | next %3d\n", index, dynamic_node,
                   dynamic_node->prior->data, dynamic_node->data, dynamic_node->next->data);
        }
    } else {
        index = 1;
        for (dynamic_node = (*list)->next->prior;
             dynamic_node && traverse_count; dynamic_node = dynamic_node->prior, index++) {
            if (dynamic_node->prior == (*list)->next->prior && index != 1)traverse_count--;
            printf("node %3d | address %p | prior %3d | value %3d | next %3d\n", index, dynamic_node,
                   dynamic_node->next->data, dynamic_node->data, dynamic_node->prior->data);
        }
    }
}
