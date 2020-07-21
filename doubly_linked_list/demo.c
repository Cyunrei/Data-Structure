#include "doubly_linked_list.h"

int main() {
    int array[] = {10, 20, 50, 60, 40, 80, 30, 100, 70, 90};
    dl_list list;
    printf("func():sl_list_init_head size:10\n");
    dl_list_init_tail(&list, array, 10);
    dl_list_traverse(&list,false);
    printf("func():sl_list_del_node index:5\n");
    dl_list_del_node(&list,10);
    dl_list_traverse(&list,false);
    printf("func():sl_list_insert_node index:2 elem:88\n");
    dl_list_insert_node(&list,2,88);
    dl_list_traverse(&list,false);
    printf("func():sl_list_traverse reserve:true\n");
    dl_list_traverse(&list,true);
    printf("func():sl_list_del\n");
    dl_list_del(&list);
    dl_list_traverse(&list,false);
    return 0;
}
