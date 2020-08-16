//
// Created by cyunrei on 8/9/20.
//

#include "linked_queue.h"

linked_queue linked_queue_init() {
    linked_queue queue;
    queue.front = (queue_ptr) malloc(sizeof(queue_node));
    if (!queue.front) exit(-1);
    queue.rear = queue.front;
    queue.front->next = NULL;
    return queue;
}

bool linked_queue_del(linked_queue *queue) {
    while ((*queue).front) {
        (*queue).rear = (*queue).front->next;
        free((*queue).front);
        (*queue).front = (*queue).rear;
    }
    return true;
}

bool linked_queue_clear(linked_queue *queue) {
    linked_queue_del(queue);
    *queue = linked_queue_init();
    return true;
}

bool linked_queue_empty(linked_queue *queue) {
    if (queue->front == queue->rear) return true;
    return false;
}

bool linked_queue_enqueue(linked_queue *queue, elem_datatype elem) {
    queue_ptr ptr = malloc(sizeof(queue_node));
    if (!ptr) return false;
    ptr->data = elem;
    ptr->next = NULL;
    queue->rear->next = ptr;
    queue->rear = ptr;
    return true;
}

bool linked_queue_dequeue(linked_queue *queue, elem_datatype *elem) {
    if (linked_queue_empty(queue)) return false;
    queue_ptr ptr = queue->front->next;
    queue->front->next = ptr->next;
    *elem = ptr->data;
    if (queue->rear == ptr) queue->rear = queue->front;
    free(ptr);
    return true;
}

bool linked_queue_get_front(linked_queue *queue, elem_datatype *elem) {
    if (linked_queue_empty(queue)) return false;
    *elem = queue->front->data;
    return true;
}

bool linked_queue_get_rear(linked_queue *queue, elem_datatype *elem) {
    if (linked_queue_empty(queue)) return false;
    *elem = queue->rear->data;
    return true;
}

bool linked_queue_traverse(linked_queue *queue) {
    if (linked_queue_empty(queue)) return false;
    queue_ptr ptr = queue->front->next;
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return true;
}

int linked_queue_len(linked_queue *queue) {
    int len = 0;
    queue_ptr ptr = queue->front;
    for (; ptr != queue->rear; len++, ptr = ptr->next);
    return len;
}
