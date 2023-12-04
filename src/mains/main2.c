#include "../../headers/cell.h"
#include "../../headers/complementary.h"
#include "../../headers/timer.h"

int main()
{
    srand(time(NULL));
    int val_search = 0;
    int num_search[4] = {1000, 10000, 100000};
    for (int level = 7; level < 15; level++)
    {
        int taille = (int)(pow(2, level) - 1);
        t_d_list* list = createEmptyList(level);
        list = fillList(list, taille);

    /*------------------------------------------------*/

        startTimer();

        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < num_search[k]; i++)
            {
                val_search = (rand() % taille) + 1;
                searchValue(*list, val_search);
            }
        }

        stopTimer();
        printf("\n|*----------------------------------*|\nlevel %d\n\n", level);
        displayTime();
        printf(" | ");

    /*------------------------------------------------*/

        startTimer();

        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < num_search[k]; i++)
            {
                val_search = (rand() % taille) + 1;
                dichoSearchValue(*list, val_search);
            }
        }

        stopTimer();
        displayTime();
        free(list);
    }
    printf("\n");
/*------------------------------------------------*/

    return 0;
}