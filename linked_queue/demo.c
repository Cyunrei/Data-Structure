#include "linked_queue.h"

int main() {
    linked_queue queue = linked_queue_init();
    printf("Init linked queue: %p\n", &queue);
    printf("Linked queue is empty: %d\n", linked_queue_empty(&queue));
    printf("Enqueue 1 element: %d\n", linked_queue_enqueue(&queue, 1));
    printf("Enqueue 2 element: %d\n", linked_queue_enqueue(&queue, 2));
    printf("Enqueue 3 element: %d\n", linked_queue_enqueue(&queue, 3));
    printf("Linked queue is empty: %d\n", linked_queue_empty(&queue));
    elem_datatype elem;
    printf("Get queue front: %d ,%d\n", elem, linked_queue_get_front(&queue, &elem));
    printf("Get queue rear: %d ,%d\n", elem, linked_queue_get_rear(&queue, &elem));
    printf("Linked queue traverse: %d\n", linked_queue_traverse(&queue));
    printf("Linked queue length: %d\n", linked_queue_len(&queue));
    printf("Linked queue is empty: %d\n", linked_queue_empty(&queue));
    printf("Linked dequeue: %d, %d\n", elem, linked_queue_dequeue(&queue, &elem));
    printf("Linked dequeue: %d, %d\n", elem, linked_queue_dequeue(&queue, &elem));
    printf("Linked dequeue: %d, %d\n", elem, linked_queue_dequeue(&queue, &elem));
    printf("Linked queue is empty: %d\n", linked_queue_empty(&queue));
    printf("Linked dequeue: %d, %d\n", elem, linked_queue_dequeue(&queue, &elem));
    printf("Enqueue 1 element: %d\n", linked_queue_enqueue(&queue, 1));
    printf("Enqueue 2 element: %d\n", linked_queue_enqueue(&queue, 2));
    printf("Enqueue 3 element: %d\n", linked_queue_enqueue(&queue, 3));
    printf("Linked queue is empty: %d\n", linked_queue_empty(&queue));
    printf("Clear queue: %d\n",linked_queue_clear(&queue));
    printf("Linked queue is empty: %d\n", linked_queue_empty(&queue));
    printf("Get queue front: %d ,%d\n", elem, linked_queue_get_front(&queue, &elem));
    printf("Get queue rear: %d ,%d\n", elem, linked_queue_get_rear(&queue, &elem));
    printf("Enqueue 1 element: %d\n", linked_queue_enqueue(&queue, 1));
    printf("Linked queue is empty: %d\n", linked_queue_empty(&queue));
    printf("Delete queue: %d\n",linked_queue_del(&queue));
    printf("Linked queue is empty: %d\n", linked_queue_empty(&queue));
    return 0;
}
