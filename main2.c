#include "cell.h"
#include "complementary.h"
#include "timer.h"

int main()
{
    t_d_list* list = createEmptyList(SIZE);
    srand(time(NULL));

    int taille = (int)(pow(2, SIZE) - 1);
    int val_search = 0;
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
        if (i != 7)
            insertHead(list, i, array[j]);
        j++;
    }

    printf("|%d|\n", list->head[0]->value);

    insertSortedCell(list, 7, 1);

/*------------------------------------------------*/

    displayAllLevel(list);
    startTimer();

    for (int i = 0; i < NUMSEARCH; i++)
    {
        val_search = (rand() % taille) + 1;
        searchValue(*list, val_search);
    }
    
    stopTimer();
    displayTime();

/*------------------------------------------------*/
    startTimer();

    for (int i = 0; i < NUMSEARCH; i++)
    {
        val_search = (rand() % taille) + 1;
        dichoSearchValue(*list, val_search);
    }
    
    stopTimer();
    displayTime();

/*------------------------------------------------*/

    free(list);
    free(array);
    return 0;
}