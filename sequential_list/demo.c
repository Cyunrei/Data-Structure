#include "sequential_list.h"

int main() {
    printf("func():sq_list_init size:5\n");
    sq_list list = sq_list_init(5);
    sq_list_traverse(&list);
    printf("func():sq_list_append_elem elem:1\n");
    sq_list_append_elem(&list,1);
    sq_list_traverse(&list);
    printf("func():sq_list_append_elem elem:2\n");
    sq_list_append_elem(&list,2);
    sq_list_traverse(&list);
    printf("func():sq_list_append_elem elem:3\n");
    sq_list_append_elem(&list,3);
    sq_list_traverse(&list);
    printf("func():sq_list_append_elem elem:4\n");
    sq_list_append_elem(&list,4);
    sq_list_traverse(&list);
    printf("func():sq_list_insert index:2 elem:0\n");
    sq_list_insert_elem(&list,2,0);
    sq_list_traverse(&list);
    printf("func():sq_list_append_elem elem:7\n");
    sq_list_append_elem(&list,7);
    sq_list_traverse(&list);
    printf("func():sq_list_append_elem elem:10\n");
    sq_list_append_elem(&list,10);
    sq_list_traverse(&list);
    printf("sq_list_len: %d\n",sq_list_len(&list));
    sq_list_traverse(&list);
    printf("elem:3 prior: %d\n",sq_list_prior_elem(&list,3));
    printf("elem:3 next: %d\n",sq_list_next_elem(&list,3));
    printf("func():sq_list_del_elem elem: 1\n");
    sq_list_del_elem(&list,1);
    sq_list_traverse(&list);
    printf("func():sq_list_del_elem elem: 10\n");
    sq_list_del_elem(&list,10);
    sq_list_traverse(&list);
    printf("func():sq_list_del_elem elem: 2\n");
    sq_list_del_elem(&list,2);
    sq_list_traverse(&list);
    printf("sq_list_len: %d\n",sq_list_len(&list));
    return 0;
}
