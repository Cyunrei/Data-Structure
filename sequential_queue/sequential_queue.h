//
// Created by cyunrei on 8/2/20.
//

#ifndef DATA_STRUCTURE_SEQUENTIAL_QUEUE_H
#define DATA_STRUCTURE_SEQUENTIAL_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

enum {
    true = 1, false = 0
};

typedef short int bool;

typedef int elem_datatype;

typedef struct {
    elem_datatype *base;
    int front;
    int rear;
    int size;
} sq_queue;

sq_queue sq_queue_init(int size);

bool sq_queue_empty(sq_queue *queue);

bool sq_queue_full(sq_queue *queue);

bool sq_queue_enqueue(sq_queue *queue,elem_datatype elem);

bool sq_queue_dequeue(sq_queue *queue, elem_datatype *elem);

elem_datatype sq_queue_queue_get_front(sq_queue *queue);

elem_datatype sq_queue_queue_get_rear(sq_queue *queue);

void sq_queue_clear(sq_queue *queue);

bool sq_queue_traverse(sq_queue *queue);

#endif //DATA_STRUCTURE_SEQUENTIAL_QUEUE_H
