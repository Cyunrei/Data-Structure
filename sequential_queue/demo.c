#include "sequential_queue.h"

int main() {
    sq_queue queue;
    elem_datatype elem;
    queue = sq_queue_init(3);
    printf("Init queue\n");
    printf("Queue is empty: %d\n", sq_queue_empty(&queue));
    printf("Queue is full: %d\n", sq_queue_full(&queue));
    printf("Enqueue elem: 1, Return: %d \n", sq_queue_enqueue(&queue, 1));
    printf("Queue is empty: %d\n", sq_queue_empty(&queue));
    printf("Enqueue elem: 2, Return: %d \n", sq_queue_enqueue(&queue, 2));
    printf("Queue front %d\n", sq_queue_queue_get_front(&queue));
    printf("Queue rear %d\n", sq_queue_queue_get_rear(&queue));
    printf("Enqueue elem: 3, Return: %d \n", sq_queue_enqueue(&queue, 3));
    printf("Queue traverse return: %d\n", sq_queue_traverse(&queue));
    printf("Queue is full: %d\n", sq_queue_full(&queue));
    printf("Enqueue elem: 4, Return: %d \n", sq_queue_enqueue(&queue, 4));
    printf("Queue traverse return: %d\n", sq_queue_traverse(&queue));
    printf("Queue front %d\n", sq_queue_queue_get_front(&queue));
    printf("Queue rear %d\n", sq_queue_queue_get_rear(&queue));
    printf("Queue dequeue:%d return %d\n", elem, sq_queue_dequeue(&queue, &elem));
    printf("Queue front %d\n", sq_queue_queue_get_front(&queue));
    printf("Queue rear %d\n", sq_queue_queue_get_rear(&queue));
    printf("Queue dequeue:%d return %d\n", elem, sq_queue_dequeue(&queue, &elem));
    printf("Queue traverse return: %d\n", sq_queue_traverse(&queue));
    printf("Queue clear\n");
    sq_queue_clear(&queue);
    printf("Queue traverse return: %d\n", sq_queue_traverse(&queue));
    return 0;
}
