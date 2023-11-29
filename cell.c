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
    for (int curlvl = 0; curlvl < levels; curlvl++)
    {
        if (list->head[curlvl] != NULL)
        {
            cell->next[curlvl] = list->head[curlvl];
            list->head[curlvl] = cell;
        }else{
            list->head[curlvl] = cell;
        }
    }
}


// void sortedInsert(t_d_list* list, int value, int levels)
// {
//     t_d_cell *tmp_cell = list->head[0];
//     t_d_list *tmp_list = NULL;
//     if (value < list->head[0]->value)
//     {
//         insertHead(list, value, levels);
//     }
//     else
//     {
//         while ((tmp_cell != NULL) && (tmp_cell->next[0]->value < value))
//         {
//             fprintf(stdout, "DDD\n");
//             tmp_cell = tmp_cell->next[0];
//         }
//         fprintf(stdout, "ABC\n");
//         // tmp_list->head = tmp_cell->next;
//         insertHead(tmp_list, value, levels);
//         fprintf(stdout, "ABC\n");
//     }
// }