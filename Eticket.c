#include "cancelation.c"
#include "rule.c"
#define MAX_LINE_LENGTH 100
void myticket(); 
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
    
    case 3:
        myticket(); 
        break;
    case 4:
        rule(); 
        break; 
    default:
        printf("\tOpps.....There was an error.\n");
        break;
    }
}  

void myticket() {
    char Phone_number[12];
    printf("\n\t\t\t\t\tEnter the Phone-Number: ");
    scanf("%s", Phone_number);

    FILE *file = fopen("registered.xlsx", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Check if the phone number exists in the current line
        if (strstr(line, Phone_number) != NULL) {
            found = 1;

            // Extract individual fields from the line
            char name[MAX_LINE_LENGTH], departure[MAX_LINE_LENGTH], destination[MAX_LINE_LENGTH], day[MAX_LINE_LENGTH], fee[MAX_LINE_LENGTH];
            sscanf(line, "%s %s %s %s %s", name, Phone_number, departure, destination, day);
            // Read the fee as the remaining part of the line
            // Assuming fee is the last part and contains no spaces
            char *ptr = strchr(line, ' ');
            if (ptr != NULL) {
                strcpy(fee, ptr + 1);
                // Remove newline character from fee if present
                char *newline = strchr(fee, '\n');
                if (newline != NULL) {
                    *newline = '\0';
                }
            }

            // Print the extracted information in the specified format
            printf("Name: %s\n", name);
            printf("Phone Number: %s\n", Phone_number);
            printf("Departure: %s\n", departure);
            printf("Destination: %s\n", destination);
            printf("Day: %s\n", day);
            printf("Fee: %s\n", fee);

            break; // Exit the loop since we found the phone number
        }
    }

    fclose(file);

    if (!found) {
        printf("Passenger with Phone Number %s not found.\n", Phone_number);
    }
}

