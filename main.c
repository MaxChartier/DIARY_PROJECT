#include "cell.h"

int main()
{
    t_d_list* list = createEmptyList(4);
    insertHead(list, 11, 0);
    insertHead(list, 12, 1);
    displayLevel(list, 1);
    displayLevel(list, 0);
    return 0;
}