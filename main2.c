#include "cell.h"
#include "complementary.h"
#include "timer.h"

int main()
{
    t_d_list* list = createEmptyList(SIZE);

    int taille = (int)(pow(2, SIZE) - 1);
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
    startTimer();
    searchValue(*list, 17);
    stopTimer();
    displayTime();
    free(list);
    free(array);
    return 0;
}