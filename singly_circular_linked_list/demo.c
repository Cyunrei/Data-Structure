#include "singly_circular_linked_list.h"

int main() {
    int array[] = {10, 20, 50, 60, 40, 80, 30, 100, 70, 90};
    scl_list list;
    printf("func():sl_list_init_head size:5\n");
    scl_list_init_head(&list, array, 5);
    scl_list_traverse(&list,2);
    scl_list_del(&list);
    printf("func():sl_list_init_tail size:6\n");
    scl_list_init_tail(&list, array, 6);
    scl_list_traverse(&list,2);
    printf("func():sl_list_del_node index:3\n");
    scl_list_del_node(&list, 3);
    scl_list_traverse(&list,2);
    printf("func():scl_list_insert index:6 elem:88\n");
    scl_list_insert_node(&list, 4, 88);
    scl_list_traverse(&list,2);
    return 0;
}
