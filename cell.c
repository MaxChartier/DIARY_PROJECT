#include "cell.h"

t_d_cell* createCell(int value, int levels)
{
    t_d_cell *cell = (t_d_cell*) malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->level = levels;
    cell->next = (t_d_cell**) malloc(sizeof(t_d_cell*) * cell->level);
    
    for (int i = 0; i < cell->level; i++)
        cell->next[i] = NULL; // Initialize all elements of the next array to NULL
    
    return cell;
}

t_d_list* createEmptyList(int maxlevel)
{
    t_d_list* list;
    list = (t_d_list*) malloc(sizeof(t_d_list));
    list->maxlevel = maxlevel;
    list->head = (t_d_cell**) malloc(sizeof(t_d_cell*) * maxlevel);
    for (int i = 0; i < maxlevel; i++)
        list->head[i] = NULL;
    return list;
}

void insertHead(t_d_list* list, int value, int levels)
{
    t_d_cell* cell = createCell(value, levels);
    for (int curlvl = 0; curlvl <= levels; curlvl++)
    {
        if (list->head[curlvl] != NULL)
        {
            cell->next[curlvl] = list->head[curlvl];
            list->head[curlvl] = cell;
        }else{
          list->head[curlvl] = cell;
        }
    }
};

void displayLevel(t_d_list* list, int level)
{
    t_d_cell* tmp = list->head[level]; // Store a pointer to the current level's head
    t_d_cell* tmp2 = list->head[0];

    printf("[list head_%d @-]--", level);

    while (tmp != NULL && tmp2 != NULL)
    {
        if (tmp2 != NULL && tmp->value == tmp2->value)
        {
            printf(">[ %d|@]--", tmp->value);
            tmp = tmp->next[level];
        }
        else
        {
            printf("----------");
        }
        tmp2 = tmp2->next[0];
    }

    printf(">NULL\n");
}

void sortedInsert(t_d_list* list, int value, int level)
{
    t_d_cell *tmp = list->head[level];
    t_d_cell *cell;
    if (value < tmp->value)
        insertHead(list, value, level);
    else
    {
        cell = createCell(value, level);
        while (value > tmp->value)
        {
            if (value < tmp->next[level]->value)
            {
                cell->next[level] = tmp->next[level];
                tmp->next[level] = cell;
            }
            tmp = tmp->next[level];
        }
        cell->next[level] = tmp->next[level];
        tmp->next[level] = cell;
    }
}

void displayALLlevel(t_d_list* list)
{
    int nbr = list->maxlevel;
    for(int i=0;i<nbr;i++){
        displayLevel(list,i);
    }
}