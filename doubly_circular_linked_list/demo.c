#include "doubly_circular_linked_list.h"

int main() {
    int array[] = {10, 20, 50, 60, 40, 80, 30, 100, 70, 90};
    dcl_list list;
    printf("func():sl_list_init_head size:5 traverse_count:1\n");
    dcl_list_init_head(&list, array, 5);
    dcl_list_traverse(&list,1,false);
    dcl_list_del(&list);
    printf("func():sl_list_init_tail size:6 traverse_count:2\n");
    dcl_list_init_tail(&list, array, 6);
    dcl_list_traverse(&list,2,false);
    printf("func():sl_list_del_node index:3\n");
    dcl_list_del_node(&list, 3);
    dcl_list_traverse(&list,2,false);
    printf("func():dcl_list_insert index:4 elem:88\n");
    dcl_list_insert_node(&list, 4, 88);
    dcl_list_traverse(&list,2,false);
    return 0;
}
