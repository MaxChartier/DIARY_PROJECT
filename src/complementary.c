#include "../headers/complementary.h"

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
    while ((found == false) && (cell != NULL))
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

// int dichoSearchValue(t_d_list list, int value)
// {
//     int cur_level = list.maxlevel;
//     t_d_cell *cell = list.head[cur_level];
//     int taille = (int)(pow(2, SIZE) - 1);
//     int n = (taille / 2) + 1;
//     int mid_val = cell->value / 2;
//     while (cell->value != value)
//     {
//         if (value > cell->value)
//         {
//             cur_level--;
//             cell = cell->next[cur_level];
//             n += mid_val;
//         }
//         else
//         {
//             cur_level--;
//             cell = list.head[cur_level];
//             n -= mid_val;
//         }
//         mid_val /= 2;
//     }
//     return n;
// }

int dichoSearchValue(t_d_list list, int value)
{
    int cur_level = list.maxlevel - 1;
    if (cur_level < 0 || cur_level >= list.maxlevel) {
        return -2;
    }

    t_d_cell *cell = list.head[cur_level];
    if (!cell) {
        return -2;
    }

    int taille = (int)(pow(2, SIZE) - 1);
    if (taille <= 0) {
        return -2;
    }

    int n = (taille / 2) + 1;
    int mid_val = cell->value / 2;

    // Ajoutez une condition pour éviter une boucle infinie si la valeur n'est pas trouvée.
    while (cell->value != value && cur_level >= 0) {
        if (value > cell->value) {
            cell = cell->next[--cur_level];
            if (cell) {
                n += mid_val;
            } else {
                return -2;
            }
        } else {
            cell = list.head[--cur_level];
            if (cell) {
                n -= mid_val;
            } else {
                return -2;
            }
        }
        mid_val /= 2;
    }

    // Ajoutez une gestion appropriée si la valeur n'est pas trouvée, par exemple, return une valeur d'erreur.
    return n;
}