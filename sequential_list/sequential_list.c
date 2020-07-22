//
// Created by cyunrei on 7/22/20.
//

#include "sequential_list.h"

sq_list sq_list_init(int size) {
    sq_list list;   //Declare sequential list.
    list.head = (elem_datatype *) malloc(size * sizeof(sq_list));   //Apply for dynamic space.
    list.len = 0;  //Define sequential list length.
    list.size = size;   //Define sequential list size.
    return list;
}

/**
 * Delete sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @return {bool} If return is true,the operation is successful.
 */

bool sq_list_del(sq_list *list) {
    if (list->head) free(list->head);   //Free up space.
    if (list->head == NULL) {
        list->len = 0;   //Reset sequential list length.
        list->size = 0;   //Reset sequential list size.
        if (!list->len && !list->size)
            return true;
    }
    return false;
}

/**
 * Clear sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param *list {sq_list} Operated sequential list.
 */

void sq_list_clear(sq_list *list) {
    list->len = 0;   //Reset sequential list length.
}

/**
 * Determine whether the sequential list is empty.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @return {bool} If return is true,the sequential list is empty.
 */

bool sq_list_is_empty(sq_list *list) {
    if (list->len) return false;   //Determine whether the length is zero.
    else return true;
}

/**
 * Get sequential list length.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @return {unsigned int} The sequential length.
 */

unsigned int sq_list_len(sq_list *list) {
    return list->len;   //Return sequential list length.
}

/**
 * Get sequential list element by index.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param index {int} Get the index of sequential list element.
 * @return {elem_datatype} Element obtained.
 */

elem_datatype sq_list_get_elem(sq_list *list, int index) {
    if (index > list->len)
        return 0;   //If the actual parameter index is greater than the length of the sequential list, return 0.
    else
        return *(list->head + index - 1);   //Return the element whose index is reduced by one after the head pointer.
}

/**
 * Get index by sequential list element.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} Get sequential list element's index.
 * @return {int} Index of element. If element not found return -1.
 */

int sq_list_elem_locate(sq_list *list, elem_datatype elem) {
    elem_datatype *head = list->head;   //Copy the actual sequential list head pointer.
    /*Traverse sequential list.*/
    for (int index = 1; index <= list->len; head++, index++) {
        if ((*head) == elem) return index;   //Element match.
    }
    return -1;   //If not found, return -1.
}

/**
 * Traverse sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 */

void sq_list_traverse(sq_list *list) {
    elem_datatype *head = list->head;   //Copy the actual list head pointer.
    /*Traverse sequential list.*/
    for (int index = 1; index <= list->len; index++, head++) {
        if (index == 1) printf("[");
        printf("%d", *head);   //Output each element.
        if (index != list->len) printf(", ");
        else printf("]\n");
    }
}

/**
 * Insert element by index of sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param index {index} Target insert index.
 * @param elem {elem_datatype} The index of sequential that will be inserted.
 * @return {bool} If return is true,the operation is successful.
 */

bool sq_list_insert_elem(sq_list *list, int index, elem_datatype elem) {
    /*Declare new sequential list head pointer, target index element pointer and temp index element pointer.*/
    elem_datatype *new_head, *target_index, *temp_index;
    if (index > list->len)
        return false;   //If the actual parameter index is greater than the length of the sequential list, return false.
    else {
        /*Determine whether index is the last element.*/
        if (index == list->len) {
            /*Allocate new space at the back end of the sequential list.*/
            if (!(new_head = (elem_datatype *) realloc(list->head, (++list->size * sizeof(elem_datatype)))))
                return false;   //Return false if the allocation fails.
            else {
                list->head = new_head;  //Swap sequential list data pointer.
                list->size++;   //Augment sequential list size.
            }
        }
        target_index = index + list->head - 1;  //Define target index(index begin is 1).
        /*Loop from the end index to target index.*/
        for (temp_index = list->head + list->len; temp_index >= target_index; temp_index--) {
            *(temp_index + 1) = *temp_index;   //Element back.
        }
        *target_index = elem;   //Insert element.
        list->len += 1;   //Augment sequential list length.
        return true;
    }
}

/**
 * Append element at the end of the sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} Append element.
 * @return {bool} If return is true,the operation is successful.
 */

bool sq_list_append_elem(sq_list *list, elem_datatype elem) {
    elem_datatype *new_head;    //Declare new sequential list data header.
    /*Determine sequential list whether size equal length.*/
    if (list->size == list->len) {
        /*Allocate new space at the back end of the sequential list.*/
        if (!(new_head = (elem_datatype *) realloc(list->head, (++list->size * sizeof(elem_datatype)))))
            return false;   //Return false if the allocation fails.
        else {
            list->head = new_head;  //Swap sequential list data pointer.
            list->size++;   //Augment sequential list size.
        }
    }
    *(list->head + list->len) = elem;   //Append new element.
    list->len++;   //Augment sequential list size.
    return true;
}

/**
 * Return prior element of target sequential list element.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} Sequential list element.
 * @return {elem_datatype} Prior element of target element.
 */

elem_datatype sq_list_prior_elem(sq_list *list, elem_datatype elem) {
    /*Traverse sequential list.*/
    for (int index = 1; index <= list->len; index++) {
        /*Match element.*/
        if (*(list->head + index - 1) == elem) {
            if (index == 1) return 0;   //If element index is one return 0.
            else {
                return *(list->head + index - 2);   //Return prior element(index begin is 1).
            }
        }
    }
    return 0;
}

/**
 * Return next element of target sequential list element.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} Sequential list element.
 * @return {elem_datatype} Next element of target element.
 */

elem_datatype sq_list_next_elem(sq_list *list, elem_datatype elem) {
    /*Traverse sequential list.*/
    for (int index = 1; index <= list->len; index++) {
        /*Match element.*/
        if (*(list->head + index - 1) == elem) {
            if (index == list->len) { return 0; }   //If element index is one return zero.
            else {
                return *(list->head + index);   //Return next element(index begin is 1).
            }
        }
    }
    return 0;
}

/**
 * Delete element by index of sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} The elem of sequential that will be deleted.
 * @return {bool} If return is true,the operation is successful.
 */

bool sq_list_del_elem(sq_list *list, elem_datatype elem) {
    int target_index = 0;   //Declare and define target index(0: default is no exist).
    /*Traverse sequential list.*/
    for (int index = 1; index <= list->len; index++) {
        /*Match element*/
        if (*(list->head + index - 1) == elem) {
            target_index = index;   //Get target index.
            break;
        }
    }
    /*Determine whether target index exists.*/
    if (target_index) {
        /*Loop from the target index to end index.*/
        for (int index = target_index; index < list->len; index++) {
            *(list->head + index - 1) = *(list->head + index);   //Element forward.
        }
        --list->len;   //Reduce sequential length.
        return true;
    }
    return false;
}


