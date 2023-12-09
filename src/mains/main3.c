#include "../../headers/cell.h"
#include "../../headers/complementary.h"
#include "../../headers/timer.h"
#include "../../headers/appointment.h"

int main()
{
    t_calendar cldr;

    cldr.list_cnt = createEmptyCntList(SIZE);

    displayLevelCnt(cldr.list_cnt, 0);

    insertContact(cldr.list_cnt, scanContact());

    displayAllLevelCnt(cldr.list_cnt);
    
    return 0;
}