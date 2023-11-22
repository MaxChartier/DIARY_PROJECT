#include "cell.h"

int main()
{
    t_d_list* list = createEmptyList(4);
    insertHead(list, 11, 1);
    insertHead(list, 12, 0);
    insertHead(list, 3, 2);
    insertHead(list, 2, 2);
    insertHead(list, 1, 2);
    sortedInsert(list, 4, 1);
    displayALLlevel(list);
    return 0;
}