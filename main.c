#include "cell.h"

int main()
{
    t_d_list* list = createEmptyList(4);
    insertHead(list, 11, 1);
    insertHead(list, 12, 2);
    fprintf(stdout, "A\n");
    displayCell(list->head[0]);
    fprintf(stdout, "B\n");
    return 0;
}