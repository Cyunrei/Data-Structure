#include "singly_linked_list.h"

int main() {
    int array[] = {10, 20, 50, 60, 40, 80, 30, 100, 70, 90};
    sl_list list;
    printf("func():sl_list_init_head size:5\n");
    sl_list_init_head(&list, array, 5);
    sl_list_traverse(&list);
    sl_list_del(&list);
    printf("func():sl_list_init_tail size:6\n");
    sl_list_init_tail(&list, array, 6);
    sl_list_traverse(&list);
    printf("func():sl_list_del_node index:3\n");
    sl_list_del_node(&list, 3);
    sl_list_traverse(&list);
    printf("func(): sl_list_insert index:6 elem:88\n");
    sl_list_insert_node(&list,4,88);
    sl_list_traverse(&list);
    return 0;
}
