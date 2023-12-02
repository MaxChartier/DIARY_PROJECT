#include "appointment.h"

char *scanString()
{
    char *string = (char*) malloc(sizeof(char)*30);
    fgets(string, sizeof(string), stdin);
    return string;
}

