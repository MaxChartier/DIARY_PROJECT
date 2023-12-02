#ifndef CONTACT_H
# define CONTACT_H

#include <string.h>
#include <ctype.h>
#include "cell.h"

typedef struct s_contact
{
    char *surname;
    char *firstname;
}t_contact;

typedef struct s_date
{
    int year;
    int month;
    int day;
}t_date;

typedef struct s_time
{
    int hour;
    int minute;
}t_time;

typedef struct s_appointment
{
    t_date date;
    t_time start;
    t_time length;
    char *purpose;
}t_appointment;

typedef struct s_calendar
{
    t_contact contact;
    t_d_list appointments;
};

char *scanString();


#endif