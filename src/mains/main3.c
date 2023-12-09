#include "../../headers/cell.h"
#include "../../headers/complementary.h"
#include "../../headers/timer.h"
#include "../../headers/appointment.h"

int main()
{
    t_calendar *cldr = NULL;
    cldr = (t_calendar*) malloc(sizeof(t_calendar));
    cldr->list_cnt = createEmptyCntList(SIZE);

    insertContact(cldr->list_cnt, scanContact());
    puts("scan\n");
    displayAllLevelCnt(cldr->list_cnt);
    puts("disp\n");
    
    return 0;
}