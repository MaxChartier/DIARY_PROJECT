#include "../headers/appointment.h"

t_list_apt* createEmptyAptList(int maxlevel)
{
    t_list_apt* list;
    list = (t_list_apt*) malloc(sizeof(t_list_apt));
    list->maxlevel = maxlevel;
    list->head = (t_cell_apt**) malloc(sizeof(t_cell_apt*) * maxlevel);
    for (int i = 0; i < maxlevel; i++)
        list->head[i] = NULL;
    return list;
}

t_list_contact* createEmptyCntList(int maxlevel)
{
    t_list_contact* list;
    list = (t_list_contact*) malloc(sizeof(t_list_contact));
    list->maxlevel = maxlevel;
    list->head = (t_cell_cnt**) malloc(sizeof(t_cell_cnt*) * maxlevel);
    for (int i = 0; i < maxlevel; i++)
        list->head[i] = NULL;
    return list;
}

t_cell_cnt* createCellCnt(int level, t_contact contact)
{
    t_cell_cnt* cell = (t_cell_cnt*) malloc(sizeof(t_cell_cnt));
    cell->contact = &contact;
    cell->level = level;
    cell->next = (t_cell_cnt**) malloc(sizeof(t_cell_cnt*) * cell->level);

    for (int i = 0; i < cell->level; i++)
        cell->next[i] = NULL;
    
    return cell;
}

char *scanString()
{
    char *string = (char*) malloc(sizeof(char)*30);
    fflush(stdin);
    string = strlower(fgets(string, 30, stdin));
    int length = strlen(string);
    if (string[length-1] == '\n')
        string[length-1] = '\0';
    return string;
}

t_contact scanContact()
{   
    t_contact contact;
    printf("Enter your first name : ");
    contact.firstname = scanString();
    printf("Enter your surname : ");
    contact.surname = scanString();
    contact.conc_name = concUnderscore(contact.surname, contact.firstname);
    return contact;
}

void displayContact(t_contact contact)
{
    printf("First Name : %s\n", contact.firstname);
    printf("Surname : %s\n", contact.surname);
    printf("Known as : %s\n", contact.conc_name);
}

char *concUnderscore(char *string1, char *string2)
{
    char middle = '_';
    char *tmp = (char*) malloc(sizeof(string1) + sizeof(middle) + sizeof(string2));
    strncat(tmp, string1, strlen(string1));
    strncat(tmp, &middle, 1);
    strncat(tmp, string2, strlen(string2));
    return tmp;
}

char *strlower(char *string)
{
    for (int i = 0; i < (int) strlen(string); i++)
        string[i] = tolower(string[i]);
    return string;
}

void insertContact(t_list_contact *list, t_contact contact)
{
    if (!list->head[0])
    {
        for (int i = 0; i < list->maxlevel; i++)
        {
            list->head[i] = createCellCnt(list->maxlevel, contact);
        }
        return;
    }

    
}