#include "cell.h"
#include "complementary.h"
#include "timer.h"

int main()
{
    t_d_list* list = createEmptyList(SIZE);

    insertHead(list, 9, 1);
    insertHead(list, 8, 2);
    insertHead(list, 4, 3);
    insertSortedCell(list, 6, 1);
    insertSortedCell(list, 12, 4);

    displayLevel(list, 0);
    displayLevel(list, 2);
    
    displayAllLevel(list);

    free(list);
    return 0;
}