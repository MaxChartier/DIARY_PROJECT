#include "cell.h"
#include "complementary.h"

int main()
{
    int n = 3;
    t_d_list* list = createEmptyList(n);

    int taille = (int)(pow(2, n) - 1);
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
        insertHead(list, i, array[j]-1);
        j++;
    }
    displayAllLevel(list);
    free(list);
    free(array);
    return 0;
}