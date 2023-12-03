#include "../../headers/cell.h"
#include "../../headers/complementary.h"
#include "../../headers/timer.h"
#include "../../headers/appointment.h"

int main()
{
    t_contact contact;
    contact = scanContact();
    printf("first name : %s\nsurname : %s\n", contact.firstname, contact.surname);
    char *string = concUnderscore(contact.firstname, contact.surname);
    printf("conc string : %s\n", string);
    printf("first name : %s\nsurname : %s\n", contact.firstname, contact.surname);
    return 0;
}