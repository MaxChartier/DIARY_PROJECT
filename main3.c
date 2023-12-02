#include "cell.h"
#include "complementary.h"
#include "timer.h"
#include "appointment.h"

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