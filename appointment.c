#include "appointment.h"

char *scanString()
{
    char *string = (char*) malloc(sizeof(char)*30);
    fflush(stdin);
    string = strlower(fgets(string, sizeof(string), stdin));
    return string;
}

t_contact scanContact()
{   
    t_contact contact;
    printf("Enter your first name : ");
    contact.firstname = scanString();
    printf("Enter your surname : ");
    contact.surname = scanString();
    return contact;
}

char *concUnderscore(char *string1, char *string2)
{
    char middle = '_';
    char *tmp = (char*) malloc(sizeof(string1) + sizeof(middle) + sizeof(string2)); 
    strncat(tmp, string2, strlen(string2));
    strncat(tmp, &middle, 1);
    strncat(tmp, string1, strlen(string1));
    return tmp;
}

char *strlower(char *string)
{
    for (int i = 0; i < (int) strlen(string); i++)
        string[i] = tolower(string[i]);
    return string;
}