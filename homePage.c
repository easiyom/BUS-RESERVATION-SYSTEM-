//#include <stdio.h>
#include "Eticket.c"
//#include "service.c"
#include "about.c"
#include "login.c"
//#include "SignUp.c"
void HomePage(){
    int choice; 
    printf("\n\n");
    printf("\t\t\t Wellocme to ODDAA Integrated Transport SC.\n\n");
    printf("\tSelect one of the following to proceed to tikieting\n"); 
    printf("\t 1. E-Ticket\n");  
    printf("\t 2. About\n");
    printf("\t 3. LogIn\n");
    printf("\t 4. SignUp\n"); 
    printf("\t Put Your Choice Here: "); 
    scanf("%d", &choice); 

    switch (choice)
    {
    case 1:
        Eticket(); 
        break;

    case 2:
        About(); 
        break;

    case 3:
        LogIn();
        break;

    case 4:
        SignUp(); 
        break; 
        
    default:
        printf("\t\tOpps........There was error!"); 
        break;
    }
}