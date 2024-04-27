#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// Define the struct bus_route

struct bus_route {
    char start_location[100];
    char end_location[100];
    char day[20];
    bool available;
};

// Fix the function prototype spelling and move the struct definition above
bool check_route(struct bus_route routes[], int num_routes, char departure[], char destination[], char day[]);
void handle_bus_route_checking(struct bus_route routes[], int num_routes); 
void odda();

// Implement the functions
bool check_route(struct bus_route routes[], int num_routes, char departure[], char destination[], char day[]) {
    for (int i = 0; i < num_routes; i++) {
        if (strcmp(routes[i].start_location, departure) == 0 && 
            strcmp(routes[i].end_location, destination) == 0 && 
            strcmp(routes[i].day, day) == 0 && 
            routes[i].available) {
            return true;
        }
    }
    return false;
}

void handle_bus_route_checking(struct bus_route routes[], int num_routes) {
    char departure[100];
    char destination[100];
    char day[20];

    printf("\tFrom/Departure: ");
    scanf(" %[^\n]", &departure);
    printf("\tTo/Destination: ");
    scanf(" %[^\n]", &destination);
    printf("\tDeparture Day: ");
    scanf(" %[^\n]", &day);

    for(int  i = 0; departure[i] != '\0'; i++){
        departure[i] = tolower(departure[i]); 
    }

    for(int i = 0; destination[i] != '\0'; i++){
        destination[i] = tolower(destination[i]); 
    }
    for(int i = 0; day[i] != '\0'; i++){
        day[i] = tolower(day[i]); 
    }
    if (check_route(routes, num_routes, departure, destination, day)) {
        printf("\t\tThere is an available bus route from %s to %s on %s.\n", departure, destination, day);
    } else {
        printf("\t\tSorry, there is no available bus route from %s to %s on %s.\n", departure, destination, day);
        exit(0); 
    }
}

void odda() {
    // Fix syntax errors in array initialization
    struct bus_route routes[] = {
        {"addis ababa", "jijiga", "monday", true},
        {"addis ababa", "hawassa", "monday", false},
        {"addis ababa", "gonder", "tuesday", true},
        {"addis ababa", "harar", "tuesday", true},
        {"addis ababa", "bahirDar", "wednesday", true},
        {"addis ababa", "debereMarkos", "thursday", false},
        {"addis ababa", "desie", "friday", true},
        {"addis ababa", "woldiya", "saturday", true},
        {"addis ababa", "jimma", "sunday", false}
    };
    int num_routes = sizeof(routes) / sizeof(routes[0]);
    handle_bus_route_checking(routes, num_routes);
}

void Registration(){ 
    odda();
    printf("\n\n");
    printf("\t\t\tCustomer Registration Form\n"); 
    int passanger; 
    printf("\n"); 
    printf("The number of Passenger: "); 
    scanf("%d", &passanger); 
    char Name[passanger][100];
    char phone[passanger][12]; 
    char departure[100];
    char destination[100];
    char day[20];
    if (passanger <= 4)
    {
        for (int  i = 0; i < passanger; i++)
        {
            printf("Name - %d: ", i + 1);
            scanf(" %[^\n]", Name[i]);
            printf("Phone Number - %d: ", i + 1);
            scanf("%s", phone[i]);
            printf("Departure - %d: ", i + 1);
            scanf(" %[^\n]", departure);
            printf("Destination - %d: ", i + 1);
            scanf(" %[^\n]", destination);
            printf("Day - %d: ", i + 1);
            scanf(" %[^\n]", day);

        }

        FILE *file = fopen("registered.txt", "a"); // open file for writting!
        if (file == NULL) {
            printf("Error opening file.\n");
            return; 
        }
        fseek(file, 0, SEEK_END); 
        bool isEmpty = ftell(file) == 0;
        rewind(file); 
        if (isEmpty) {
            fprintf(file, "Name of Passenger\t\tPhone Number\t\tDeprature\t\tDestination\t\tDay\n");
        }

        for(int i = 0; i < passanger;i++){
            fprintf(file, "%-20s\t%-12s\t%-20s\t%-20s\t%-20s\n", Name[i], phone[i], departure, destination, day);
        }
    
        fprintf(file,"\n");
        fclose(file); 
        printf("\n");
        printf("\t\t\tThank You Dear Customer. You successfully registerd.\n");
        
    }else{
        printf("\n"); 
        printf("\t\tSorry Passenger. You only allowed to Book Ticket Atmost for FOUR person.\n");  
    }
    printf("\n\n");
} 