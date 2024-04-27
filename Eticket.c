#include "cancelation.c"
#include "rule.c"
void Eticket(){
    int choice2; //to accept the choice of the passanger.
    printf("\t\t\t Wellcome To ODDAA Bus Customer E-ticketing Page\n\n");
    printf("\tDear Passanger you can select one of the following.\n"); 
    printf("\t\t1. Registration\n");
    printf("\t\t2. Cancelation\n");
    printf("\t\t3. My Ticket\n");
    printf("\t\t4. Rule\n"); 
    printf("\t\t\t\tPut Your Choice Here:: "); 
    scanf("%d", &choice2); 
    
    switch (choice2)
    {
    case 1:
        Registration(); 
        break;
    
    case 2:
        cancel(); 
        break;
    /*
    case 3:
        generate_online_ticket(); 
        break;
    */
    case 4:
        rule(); 
        break; 
    default:
        printf("\tOpps.....There was an error.\n");
        break;
    }
}  