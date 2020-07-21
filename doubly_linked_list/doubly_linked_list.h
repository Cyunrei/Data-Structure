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

dl_list dl_list_init_head(dl_list *list, const elem_datatype *array, int length) {
    dl_list new_node;
    *list = (dl_list) malloc(sizeof(dual_node));
    (*list)->prior = NULL;
    (*list)->next = NULL;
    for (int i = 0; i < length; i++) {
        new_node = (dl_list) malloc(sizeof(dual_node));
        new_node->data = array[i];
        new_node->next = (*list)->next;
        if ((*list)->next != NULL) (*list)->next->prior = new_node;
        (*list)->next = new_node;
        new_node->prior = *list;
    }
    return *list;
}

/**
 * Initialize doubly linked list by tail insert method.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param array {elem_datatype} As initialization parameter.
 * @param length {int} The length of the array.
 * @return {dl_list} Doubly linked list after initialization.
 */

dl_list dl_list_init_tail(dl_list *list, const elem_datatype *array, int length) {
    *list = (dl_list) malloc(sizeof(dual_node));
    (*list)->prior = NULL;
    (*list)->next = NULL;
    int i;
    dl_list new_node, dynamic_node;
    for (i = 0, dynamic_node = (*list); i < length; i++, dynamic_node->next = new_node, dynamic_node = new_node) {
        new_node = (dl_list) malloc(sizeof(dual_node));
        new_node->data = array[i];
        new_node->prior = dynamic_node;
    }
    new_node->next = NULL;
    return *list;
}

/**
 * Traverse doubly linked list and print node info.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 */

void dl_list_traverse(dl_list *list, bool reverse) {
    dl_list dynamic_node;
    int index;
    if (!reverse) {
        for (index = 1, dynamic_node = (*list)->next; dynamic_node; dynamic_node = dynamic_node->next, index++) {
            if (dynamic_node->next)
                printf("node %3d | address %p | prior %3d | value %3d | next %3d\n", index, dynamic_node,
                       dynamic_node->prior->data, dynamic_node->data, dynamic_node->next->data);
            else
                printf("node %3d | address %p | prior %3d | value %3d | next %3d\n", index, dynamic_node,
                       dynamic_node->prior->data, dynamic_node->data, 0);
        }
    } else {
        for (index = 1, dynamic_node = (*list)->next; dynamic_node->next; index++, dynamic_node = dynamic_node->next);
        for (; dynamic_node; dynamic_node = dynamic_node->prior, index--) {
            if (!dynamic_node->next)
                printf("node %3d | address %p | prior %3d | value %3d | next %3d\n", index, dynamic_node,
                       dynamic_node->prior->data, dynamic_node->data, 0);
            else
                printf("node %3d | address %p | prior %3d | value %3d | next %3d\n", index, dynamic_node,
                       dynamic_node->prior->data, dynamic_node->data, dynamic_node->next->data);
        }
    }
}

/**
 * Delete a node of doubly linked list.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param index {int} Target index of the node will be deleted.
 * @return {bool} If return is true,the operation is successful.
 */

bool dl_list_del_node(dl_list *list, int index) {
    dl_list dynamic_node, temp_node;
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
 * Insert a node element of doubly linked list(Between head and tail).
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param index {int} Target index of the node will be insert.
 * @param elem {elem_datatype} The element will be insert in doubly linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool dl_list_insert_node(dl_list *list, int index, elem_datatype elem) {
    dl_list dynamic_node, new_node;
    int i;
    for (i = 1, dynamic_node = *list; dynamic_node && i < index; i++, dynamic_node = dynamic_node->next);
    if (!dynamic_node || index > i) return false;
    new_node = (dl_list) malloc(sizeof(dual_node));
    new_node->data = elem;
    new_node->prior = dynamic_node;
    new_node->next = dynamic_node->next;
    dynamic_node->next = new_node;
    new_node->next->prior = new_node;
    return true;
}


/**
 * Doubly linked list sort.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @param reverse {bool} Whether to sort from large to small(reverse equal true).
 */

void dl_list_sort(dl_list *list, bool reverse) {
    //TODO
}

/**
 * Delete doubly linked list.
 * @author cyunrei
 * @data July 21 2020
 * @param list {dl_list} Operated doubly linked list.
 * @return {bool} If return is true,the operation is successful.
 */

bool dl_list_del(dl_list *list) {
    dl_list node, next_node;
    node = (*list)->next;
    while (node) {
        next_node = node->next;
        free(node);
        node = next_node;
    }
    (*list)->next = NULL;
    return true;
}

#endif //DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
