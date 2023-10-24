#include "cell.h"

t_d_cell* createEmptyCell(int value, int levels)
{
    t_d_cell *cell = (t_d_cell*) malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->level = levels;
    cell->next = (t_d_cell**) malloc(sizeof(t_d_cell*) * levels);
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
    t_d_cell* cell = createEmptyCell(value, levels);
    for (int i = 0; i < list->maxlevel; i++)
    {
        if (list->head[i] != NULL)
        {
            cell->next[i] = list->head[i];
            list->head[i] = cell;
        }
    }
}

// void displayCell(t_d_cell* cell)
// {
//     printf("Value : %d\nLevel : %d\n", cell->value, cell->level);
// }

void DisplayLevel(t_d_list t, int level)
{
    while (t.head[level]->next !=NULL)
    {
        printf("%d", t.head[level]->value);
        t.head[level] = t.head[level]->next;
    }
}

// void showAllLevels(t_d_list t)
// {
//     int i;
//     while(i <= t.maxlevel)
//     {
//         DisplayLevel(t,i);
//         i++;
//     }
// }