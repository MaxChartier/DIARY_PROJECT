#include "complementary.h"

void displayLevel(t_d_list* list, int level)
{
    t_d_cell* tmp = list->head[level]; // Store a pointer to the current level's head
    t_d_cell* tmp2 = list->head[0];

    printf("[list head_%d @-]--", level);

    while (tmp != NULL && tmp2 != NULL)
    {
        if (tmp2 != NULL && (tmp->value == tmp2->value))
        {
            printf(">[ %d|@]--", tmp->value);
            tmp = tmp->next[level];
        }
        else
        {
            if (tmp2->value > 9)
                printf("----------");
            else
                printf("---------");
        }
        tmp2 = tmp2->next[0];
    }
    while (tmp==NULL && tmp2!=NULL)
    {   
        if (tmp2->value > 9)
            printf("----------");
        else
            printf("---------");
        tmp2 = tmp2->next[0];
    }
    printf(">NULL\n");
}

void displayAllLevel(t_d_list* list)
{
    int nbr = list->maxlevel;
    for (int i=0;i<nbr;i++)
        displayLevel(list,i);
}

int searchValue(t_d_list list, int value) // return the place of the cell containing the value if found, -1 otherwise
{
    t_d_cell *cell = list.head[0];
    int n = 0;
    bool found = false;
    while ((found == false) && (cell->next[0] != NULL))
    {
        if (cell->value == value)
            found = true;
        cell = cell->next[0];
        n++;
    }
    if (found == true)
        return n;
    else
        return -1;
}