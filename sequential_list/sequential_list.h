//
// Created by cyunrei on 7/17/20.
//

#ifndef DATA_STRUCTURE_SEQUENTIAL_LIST_H
#define DATA_STRUCTURE_SEQUENTIAL_LIST_H

#include <stdlib.h>
#include <stdio.h>

enum {
    true = 1, false = 0   //Enumerate boolean type
};

typedef int elem_datatype;   //Define element data type
typedef short int bool;   //Define boolean type

typedef struct {   //Define sequential list data type
    elem_datatype *head;   //Declare sequential list data head pointer
    unsigned int len;   //Declare sequential list length
    unsigned int size;   //Declare sequential list size
} sq_list;

sq_list sq_list_init(int size) {
    sq_list list;   //Declare sequential list
    list.head = (elem_datatype *) malloc(size * sizeof(sq_list));   //Apply for dynamic space
    list.len = 0;  //Define sequential list length
    list.size = size;   //Define sequential list size
    return list;
}

bool sq_list_del(sq_list *list) {
    if (list->head) free(list->head);   //Free up space
    if (list->head == NULL) {
        list->len = 0;   //Reset sequential list length
        list->size = 0;   //Reset sequential list size
        if (!list->len && !list->size)
            return true;
    }
    return false;
}

void sq_list_clear(sq_list *list) {
    list->len = 0;   //Reset sequential list length
}

bool sq_list_is_empty(sq_list *list) {
    if (list->len) return false;   //Determine whether the length is zero
    else return true;
}

unsigned int sq_list_len(sq_list *list) {
    return list->len;   //Return sequential list length
}

elem_datatype sq_list_get_elem(sq_list *list, int index) {
    if (index > list->len)
        return 0;   //If the actual parameter index is greater than the length of the sequential list, return zero
    else
        return *(list->head + index - 1);   //Return the element whose index is reduced by one after the head pointer
}

int sq_list_elem_locate(sq_list *list, elem_datatype elem) {
    elem_datatype *head = list->head;   //Copy the actual sequential list head pointer
    /*Traverse sequential list*/
    for (int index = 1; index <= list->len; head++, index++) {
        if ((*head) == elem) return index;   //Element match
    }
    return -1;   //If not match, return -1
}

void sq_list_traverse(sq_list *list) {
    elem_datatype *head = list->head;   //Copy the actual list head pointer
    /*Traverse sequential list*/
    for (int index = 1; index <= list->len; index++, head++) {
        if (index == 1) printf("[");
        printf("%d", *head);   //Output each element
        if (index != list->len) printf(", ");
        else printf("]\n");
    }
}

bool sq_list_insert_elem(sq_list *list, int index, elem_datatype elem) {
    elem_datatype *new_head, *target_index, *temp_index;   //Declare new sequential list head pointer, target index element pointer and temp index element pointer
    if (index > list->len)
        return false;   //If the actual parameter index is greater than the length of the sequential list, return false
    else {
        /*Determine whether index is the last element*/
        if (index == list->len) {
            /*Allocate new space at the back end of the sequential list*/
            if (!(new_head = (elem_datatype *) realloc(list->head, (++list->size * sizeof(elem_datatype)))))
                return false;   //Return false if the allocation fails
            else {
                list->head = new_head;  //Swap sequential list data pointer
                list->size++;   //Augment sequential list size
            }
        }
        target_index = index + list->head - 1;  //Define target index (index begin is one)
        /*Loop from the end index to target index*/
        for (temp_index = list->head + list->len; temp_index >= target_index; temp_index--) {
            *(temp_index + 1) = *temp_index;   //Element back
        }
        *target_index = elem;   //Insert element
        list->len += 1;   //Augment sequential list length
        return true;
    }
}

bool sq_list_append_elem(sq_list *list, elem_datatype elem) {
    elem_datatype *new_head;    //Declare new sequential list data header
    /*Determine sequential list whether size equal length*/
    if (list->size == list->len) {
        /*Allocate new space at the back end of the sequential list*/
        if (!(new_head = (elem_datatype *) realloc(list->head, (++list->size * sizeof(elem_datatype)))))
            return false;   //Return false if the allocation fails
        else {
            list->head = new_head;  //Swap sequential list data pointer
            list->size++;   //Augment sequential list size
        }
    }
    *(list->head + list->len) = elem;   //Append new element
    list->len++;   //Augment sequential list size
    return true;
}

elem_datatype sq_list_prior_elem(sq_list *list, elem_datatype elem) {
    /*Traverse sequential list*/
    for (int index = 1; index <= list->len; index++) {
        /*Match element*/
        if (*(list->head + index - 1) == elem) {
            if (index == 1) return 0;   //If element index is one return zero
            else {
                return *(list->head + index - 2);   //Return prior element (index begin is one)
            }
        }
    }
    return 0;
}

elem_datatype sq_list_next_elem(sq_list *list, elem_datatype elem) {
    /*Traverse sequential list*/
    for (int index = 1; index <= list->len; index++) {
        /*Match element*/
        if (*(list->head + index - 1) == elem) {
            if (index == list->len) { return 0; }   //If element index is one return zero
            else {
                return *(list->head + index);   //Return next element (index begin is one)
            }
        }
    }
    return 0;
}

bool sq_list_del_elem(sq_list *list, elem_datatype elem) {
    int target_index = 0;   //Declare and define target index (zero: default is no exist)
    /*Traverse sequential list*/
    for (int index = 1; index <= list->len; index++) {
        /*Match element*/
        if (*(list->head + index - 1) == elem) {
            target_index = index;   //Get target index
            break;
        }
    }
    /*Determine whether target index exists*/
    if (target_index) {
        /*Loop from the target index to end index*/
        for (int index = target_index; index < list->len; index++) {
            *(list->head + index - 1) = *(list->head + index);   //Element forward
        }
        --list->len;   //Reduce sequential length
        return true;
    }
    return false;
}

#endif //DATA_STRUCTURE_SEQUENTIAL_LIST_H
