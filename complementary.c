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