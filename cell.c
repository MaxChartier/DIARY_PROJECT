#include "cell.h"

t_d_cell* createEmptyCell(int value, int levels)
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
    t_d_cell* cell = createEmptyCell(value, levels);
    for (int i = 0; i <= levels; i++)
    {
        if (list->head[i] != NULL)
        {
            cell->next[i] = list->head[i];
            list->head[i] = cell;
        }else{
          list->head[i] = cell;
        }
    }
}

void displayLevel(t_d_list* list, int level)
{
    t_d_cell* tmp = list->head[level]; // Store a pointer to the current level's head
    fprintf(stdout, "A\n");
    
    while (tmp != NULL) // Change the loop condition to iterate through the linked list
    {
        fprintf(stdout, "B\n");
        printf("%d", tmp->value);
        fprintf(stdout, "C\n");
        
        if (tmp->next != NULL && tmp->next[level] != NULL) // Check the specific level in the next array
            tmp = tmp->next[level];
        fprintf(stdout, "D\n");
    }
}

// void displayCell(t_d_cell* cell)
// {
//     printf("Value : %d\nLevel : %d\n", cell->value, cell->level);
// }

// void showAllLevels(t_d_list t)
// {
//     int i;
//     while(i <= t.maxlevel)
//     {
//         DisplayLevel(t,i);
//         i++;
//     }
// }