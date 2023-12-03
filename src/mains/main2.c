#include "../../headers/cell.h"
#include "../../headers/complementary.h"
#include "../../headers/timer.h"

int main()
{
    t_d_list* list = createEmptyList(SIZE);
    srand(time(NULL));

    int taille = (int)(pow(2, SIZE) - 1);
    int val_search = 0;
    int num_search[4] = {1000, 10000, 100000};
    int count = 2;
    int *array;
    array = (int*) malloc(sizeof(int) * taille);
    for (int i = 0; i < taille; i++)
        array[i] = 1;

    while (count < taille)
    {
        for (int i = 0; i < taille; i++)
        {
            if (((i+1) % count) == 0)
            {
                array[i] += 1;
            }
        }
        count *= 2;
    }
    int j = 0;
    for (int i = taille; i > 0; i--)
    {
        insertHead(list, i, array[j]);
        j++;
    }

    displayAllLevel(list);

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
    displayTime();

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

/*------------------------------------------------*/

    free(list);
    free(array);
    return 0;
}