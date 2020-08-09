//
// Created by cyunrei on 8/2/20.
//

#include "sequential_queue.h"

sq_queue sq_queue_init(int size) {
    sq_queue queue;
    queue.front = queue.rear = 0;
    queue.base = malloc(sizeof(queue.base) * (size + 1));
    queue.size = size + 1;
    return queue;
}

bool sq_queue_empty(sq_queue *queue) {
    if (queue->rear == queue->front) return true;
    return false;
}

bool sq_queue_full(sq_queue *queue) {
    if ((queue->rear + 1) % queue->size == queue->front) return true;
    return false;
}

bool sq_queue_enqueue(sq_queue *queue, elem_datatype elem) {
    if (sq_queue_full(queue)) return false;
    else {
        queue->base[queue->rear] = elem;
        queue->rear = (queue->rear + 1) % queue->size;
        return true;
    }
}

bool sq_queue_dequeue(sq_queue *queue, elem_datatype *elem) {
    if (sq_queue_empty(queue)) return false;
    else {
        *elem = queue->base[queue->front];
        queue->front = (queue->front + 1) % queue->size;
        return true;
    }
}

elem_datatype sq_queue_queue_get_front(sq_queue *queue) {
    return queue->base[queue->front];
}

elem_datatype sq_queue_queue_get_rear(sq_queue *queue) {
    return queue->base[queue->rear-1];
}

void sq_queue_clear(sq_queue *queue) {
    queue->rear = queue->front;
}

bool sq_queue_traverse(sq_queue *queue) {
    if (sq_queue_empty(queue)) return false;
    else {
        for (int p = queue->front; p != queue->rear; p = (p + 1) % queue->size) {
            printf("%d ", *(queue->base + p));
        }
        printf("\n");
        return true;
    }
}
