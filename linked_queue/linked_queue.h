//
// Created by cyunrei on 8/9/20.
//

#ifndef DATA_STRUCTURE_LINKED_QUEUE_H
#define DATA_STRUCTURE_LINKED_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

enum {
    true = 1, false = 0
};

typedef short int bool;

typedef int elem_datatype;

typedef struct queue_node {
    elem_datatype data;
    struct queue_node *next;
} queue_node, *queue_ptr;

typedef struct {
    queue_ptr front;
    queue_ptr rear;
} linked_queue;

linked_queue linked_queue_init();

bool linked_queue_del(linked_queue *queue);

bool linked_queue_clear(linked_queue *queue);

bool linked_queue_empty(linked_queue *queue);

bool linked_queue_enqueue(linked_queue *queue, elem_datatype elem);

bool linked_queue_dequeue(linked_queue *queue, elem_datatype *elem);

bool linked_queue_get_front(linked_queue *queue,elem_datatype *elem);

bool linked_queue_get_rear(linked_queue *queue,elem_datatype *elem);

bool linked_queue_traverse(linked_queue *queue);

int linked_queue_len(linked_queue *queue);


#endif //DATA_STRUCTURE_LINKED_QUEUE_H
