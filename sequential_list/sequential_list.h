//
// Created by cyunrei on 7/17/20.
//

#ifndef DATA_STRUCTURE_SEQUENTIAL_LIST_H
#define DATA_STRUCTURE_SEQUENTIAL_LIST_H

#include <stdlib.h>
#include <stdio.h>

/*Enumerate boolean type.*/
enum {
    true = 1, false = 0
};

typedef int elem_datatype;   //Define element data type.
typedef short int bool;   //Define boolean type.

/*Define sequential list data type.*/
typedef struct {
    elem_datatype *head;   //Declare sequential list data head pointer.
    unsigned int len;   //Declare sequential list length.
    unsigned int size;   //Declare sequential list size.
} sq_list;

/**
 * Initialize sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param size {int} The size of the sequential list after initialization.
 * @return {sq_list} Sequential list after initialization.
 */

sq_list sq_list_init(int size);

/**
 * Delete sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @return {bool} If return is true,the operation is successful.
 */

bool sq_list_del(sq_list *list);

/**
 * Clear sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param *list {sq_list} Operated sequential list.
 */

void sq_list_clear(sq_list *list);

/**
 * Determine whether the sequential list is empty.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @return {bool} If return is true,the sequential list is empty.
 */

bool sq_list_is_empty(sq_list *list);

/**
 * Get sequential list length.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @return {unsigned int} The sequential length.
 */

unsigned int sq_list_len(sq_list *list);

/**
 * Get sequential list element by index.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param index {int} Get the index of sequential list element.
 * @return {elem_datatype} Element obtained.
 */

elem_datatype sq_list_get_elem(sq_list *list, int index);

/**
 * Get index by sequential list element.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} Get sequential list element's index.
 * @return {int} Index of element. If element not found return -1.
 */

int sq_list_elem_locate(sq_list *list, elem_datatype elem);

/**
 * Traverse sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 */

void sq_list_traverse(sq_list *list);

/**
 * Insert element by index of sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param index {index} Target insert index.
 * @param elem {elem_datatype} The index of sequential that will be inserted.
 * @return {bool} If return is true,the operation is successful.
 */

bool sq_list_insert_elem(sq_list *list, int index, elem_datatype elem);

/**
 * Append element at the end of the sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} Append element.
 * @return {bool} If return is true,the operation is successful.
 */

bool sq_list_append_elem(sq_list *list, elem_datatype elem);

/**
 * Return prior element of target sequential list element.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} Sequential list element.
 * @return {elem_datatype} Prior element of target element.
 */

elem_datatype sq_list_prior_elem(sq_list *list, elem_datatype elem);

/**
 * Return next element of target sequential list element.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} Sequential list element.
 * @return {elem_datatype} Next element of target element.
 */

elem_datatype sq_list_next_elem(sq_list *list, elem_datatype elem);

/**
 * Delete element by index of sequential list.
 * @author cyunrei
 * @data July 19 2020
 * @param list {sq_list} Operated sequential list.
 * @param elem {elem_datatype} The elem of sequential that will be deleted.
 * @return {bool} If return is true,the operation is successful.
 */

bool sq_list_del_elem(sq_list *list, elem_datatype elem);

#endif //DATA_STRUCTURE_SEQUENTIAL_LIST_H
