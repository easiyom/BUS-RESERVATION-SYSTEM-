# Bus Reservation System - Developer Guide

## Quick Start

### Building and Running the Application

```bash
# Compile the application
gcc -o bus_reservation main.c -std=c99

# Run the application
./bus_reservation
```

### Project Structure Overview

```
bus-reservation-system/
├── main.c              # Application entry point
├── homePage.c          # Main menu interface
├── Eticket.c           # E-ticketing module
├── Registration.c      # Booking and route management
├── SignUp.c            # User account creation
├── login.c             # User authentication
├── about.c             # Company information
├── cancelation.c       # Ticket cancellation
├── rule.c              # Rules and regulations
├── README.md           # Project overview
├── API_DOCUMENTATION.md # Complete API reference
└── DEVELOPER_GUIDE.md  # This file
```

## Code Examples and Usage Patterns

### Creating a New Menu Module

When adding a new menu module, follow this pattern:

```c
// newmodule.c
#include <stdio.h>

void NewModule() {
    int choice;
    printf("\n\t\t\t New Module Menu\n");
    printf("\t1. Option 1\n");
    printf("\t2. Option 2\n");
    printf("\tEnter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            // Handle option 1
            break;
        case 2:
            // Handle option 2
            break;
        default:
            printf("\tInvalid choice!\n");
            break;
    }
}
```

### File I/O Pattern

The system uses a consistent pattern for file operations:

```c
void writeToFile(const char* filename, const char* data) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    // Check if file is empty and write header if needed
    fseek(file, 0, SEEK_END);
    bool isEmpty = ftell(file) == 0;
    rewind(file);
    
    if (isEmpty) {
        fprintf(file, "Header1\t\tHeader2\t\tHeader3\n");
    }
    
    fprintf(file, "%s\n", data);
    fclose(file);
}
```

### Input Validation Pattern

```c
void getValidatedInput(char* buffer, int maxLength, const char* prompt) {
    printf("%s", prompt);
    scanf(" %[^\n]", buffer);
    
    // Convert to lowercase for consistency
    for (int i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = tolower(buffer[i]);
    }
    
    // Remove newline characters
    buffer[strcspn(buffer, "\n")] = '\0';
}
```

## Implementation Guidelines

### Adding New Routes

To add new bus routes, modify the `odda()` function in `Registration.c`:

```c
void odda() {
    struct bus_route routes[] = {
        // Existing routes...
        {"addis ababa", "jijiga", "monday", true},
        
        // Add new routes here
        {"addis ababa", "new_city", "wednesday", true},
        {"new_city", "addis ababa", "friday", true}
    };
    
    int num_routes = sizeof(routes) / sizeof(routes[0]);
    handle_bus_route_checking(routes, num_routes);
}
```

### Extending User Authentication

To add more user fields, extend the `User` struct:

```c
struct User {
    char username[USER_LENGTH];
    char password[PASSWORD_LENGTH];
    char email[100];          // New field
    char phone[15];           // New field
    bool isActive;            // New field
};
```

Update the `SignUp()` and `LogIn()` functions accordingly.

### Adding New Data Validation

Create validation functions for specific data types:

```c
bool isValidPhoneNumber(const char* phone) {
    if (strlen(phone) < 10 || strlen(phone) > 12) {
        return false;
    }
    
    for (int i = 0; phone[i] != '\0'; i++) {
        if (!isdigit(phone[i])) {
            return false;
        }
    }
    
    return true;
}

bool isValidName(const char* name) {
    if (strlen(name) < 2 || strlen(name) > 50) {
        return false;
    }
    
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    
    return true;
}
```

## Common Development Tasks

### Adding a New Feature to the Main Menu

1. Update `homePage.c` to include the new option:

```c
void HomePage() {
    int choice;
    printf("\n\n");
    printf("\t\t\t Welcome to ODDAA Integrated Transport SC.\n\n");
    printf("\tSelect one of the following to proceed to ticketing\n");
    printf("\t 1. E-Ticket\n");
    printf("\t 2. About\n");
    printf("\t 3. LogIn\n");
    printf("\t 4. SignUp\n");
    printf("\t 5. New Feature\n");  // Add new option
    printf("\t Put Your Choice Here: ");
    scanf("%d", &choice);

    switch (choice) {
        // ... existing cases ...
        case 5:
            NewFeature();  // Call new feature function
            break;
        default:
            printf("\t\tOpps........There was error!");
            break;
    }
}
```

2. Include the new module at the top of `homePage.c`:

```c
#include "newfeature.c"
```

### Creating a Search Function

```c
void searchPassengerByName(const char* name) {
    FILE *file = fopen("registered.xlsx", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    bool found = false;
    
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name) != NULL) {
            printf("Found: %s", line);
            found = true;
        }
    }
    
    fclose(file);
    
    if (!found) {
        printf("No passenger found with name: %s\n", name);
    }
}
```

### Implementing Data Export

```c
void exportToCSV(const char* inputFile, const char* outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");
    
    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), input)) {
        // Convert tabs to commas for CSV format
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '\t') {
                line[i] = ',';
            }
        }
        fprintf(output, "%s", line);
    }
    
    fclose(input);
    fclose(output);
    printf("Data exported to %s\n", outputFile);
}
```

## Testing and Debugging

### Unit Testing Pattern

Create simple test functions for critical components:

```c
void testRouteValidation() {
    struct bus_route testRoutes[] = {
        {"addis ababa", "jijiga", "monday", true}
    };
    
    // Test valid route
    bool result1 = check_route(testRoutes, 1, "addis ababa", "jijiga", "monday");
    printf("Test 1 (Valid route): %s\n", result1 ? "PASS" : "FAIL");
    
    // Test invalid route
    bool result2 = check_route(testRoutes, 1, "addis ababa", "nonexistent", "monday");
    printf("Test 2 (Invalid route): %s\n", !result2 ? "PASS" : "FAIL");
}
```

### Debug Logging

Add debug logging for troubleshooting:

```c
#define DEBUG 1

void debugLog(const char* message) {
    #if DEBUG
    printf("[DEBUG] %s\n", message);
    #endif
}

// Usage in functions
void Registration() {
    debugLog("Starting registration process");
    // ... function code ...
    debugLog("Registration completed");
}
```

### Memory Leak Detection

Add memory tracking for dynamic allocations:

```c
void checkMemoryLeaks() {
    if (users != NULL) {
        printf("Warning: Users array not freed\n");
    }
}

// Call at program exit
int main() {
    HomePage();
    checkMemoryLeaks();
    return 0;
}
```

## Performance Optimization

### File I/O Optimization

```c
// Instead of opening/closing files repeatedly
void batchWriteRegistrations(struct Registration* regs, int count) {
    FILE *file = fopen("registered.xlsx", "a");
    if (file == NULL) return;
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%-20s\t%-12s\t%-20s\t%-20s\t%-20s\n",
                regs[i].name, regs[i].phone, regs[i].departure,
                regs[i].destination, regs[i].day);
    }
    
    fclose(file);
}
```

### Memory Pool for User Management

```c
#define MAX_USERS 1000
struct User userPool[MAX_USERS];
int userCount = 0;

bool addUser(const char* username, const char* password) {
    if (userCount >= MAX_USERS) {
        return false;
    }
    
    strcpy(userPool[userCount].username, username);
    strcpy(userPool[userCount].password, password);
    userCount++;
    return true;
}
```

## Security Best Practices

### Input Sanitization

```c
void sanitizeInput(char* input) {
    // Remove potentially dangerous characters
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';' || input[i] == '|' || input[i] == '&') {
            input[i] = '_';
        }
    }
}
```

### Password Hashing (Basic Example)

```c
#include <stdint.h>

uint32_t simpleHash(const char* str) {
    uint32_t hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash;
}

// Use in SignUp function
void SignUp() {
    // ... get password input ...
    uint32_t hashedPassword = simpleHash(newUser.password);
    // Store hashedPassword instead of plain text
}
```

## Error Handling Improvements

### Centralized Error Handling

```c
typedef enum {
    ERROR_NONE = 0,
    ERROR_FILE_NOT_FOUND,
    ERROR_MEMORY_ALLOCATION,
    ERROR_INVALID_INPUT,
    ERROR_ROUTE_NOT_AVAILABLE
} ErrorCode;

void handleError(ErrorCode error, const char* context) {
    switch (error) {
        case ERROR_FILE_NOT_FOUND:
            printf("Error: File not found in %s\n", context);
            break;
        case ERROR_MEMORY_ALLOCATION:
            printf("Error: Memory allocation failed in %s\n", context);
            break;
        case ERROR_INVALID_INPUT:
            printf("Error: Invalid input in %s\n", context);
            break;
        case ERROR_ROUTE_NOT_AVAILABLE:
            printf("Error: Route not available in %s\n", context);
            break;
        default:
            printf("Unknown error in %s\n", context);
    }
}
```

### Graceful Shutdown

```c
void gracefulShutdown() {
    // Clean up resources
    if (users != NULL) {
        free(users);
        users = NULL;
    }
    
    // Close any open files
    printf("System shutting down gracefully...\n");
}

// Register cleanup function
#include <signal.h>

void signalHandler(int sig) {
    gracefulShutdown();
    exit(0);
}

int main() {
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    
    HomePage();
    gracefulShutdown();
    return 0;
}
```

## Code Style Guidelines

### Naming Conventions

```c
// Functions: PascalCase for public, camelCase for private
void HomePage();           // Public function
void handleUserInput();    // Private function

// Variables: camelCase
int passengerCount;
char userName[50];

// Constants: UPPER_SNAKE_CASE
#define MAX_PASSENGERS 4
#define USER_LENGTH 50

// Structs: PascalCase
struct BusRoute;
struct UserAccount;
```

### Function Documentation

```c
/**
 * @brief Validates if a bus route is available
 * @param routes Array of available routes
 * @param numRoutes Number of routes in the array
 * @param departure Departure city (case-insensitive)
 * @param destination Destination city (case-insensitive)
 * @param day Day of travel (case-insensitive)
 * @return true if route is available, false otherwise
 */
bool check_route(struct bus_route routes[], int numRoutes,
                char departure[], char destination[], char day[]);
```

## Future Enhancements

### Modular Design Improvements

```c
// Create a separate header file: bus_system.h
#ifndef BUS_SYSTEM_H
#define BUS_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function declarations
void HomePage();
void Eticket();
void Registration();
// ... other function declarations

#endif
```

### Database Integration

Consider replacing file-based storage with a database:

```c
// Pseudo-code for database integration
#include <sqlite3.h>

int initDatabase() {
    sqlite3 *db;
    int rc = sqlite3_open("bus_system.db", &db);
    
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    // Create tables
    char *sql = "CREATE TABLE IF NOT EXISTS users ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "username TEXT UNIQUE NOT NULL,"
                "password TEXT NOT NULL);";
    
    sqlite3_exec(db, sql, 0, 0, 0);
    sqlite3_close(db);
    return 0;
}
```

### Configuration Management

```c
// config.h
struct Config {
    int maxPassengers;
    char dataDirectory[256];
    bool debugMode;
};

extern struct Config globalConfig;

// config.c
struct Config globalConfig = {
    .maxPassengers = 4,
    .dataDirectory = "./data/",
    .debugMode = false
};
```

## Troubleshooting Common Issues

### Compilation Errors

1. **Undefined function errors**: Ensure all `.c` files are included in the correct order
2. **Multiple definition errors**: Use header guards or include files only where needed
3. **Library linking errors**: Add `-std=c99` flag for C99 features

### Runtime Issues

1. **Segmentation faults**: Check for null pointer dereferences and array bounds
2. **File not found**: Ensure data files are created before reading
3. **Memory leaks**: Always free allocated memory

### Performance Issues

1. **Slow file operations**: Consider buffering or batch operations
2. **High memory usage**: Use static arrays instead of dynamic allocation where possible

---

This developer guide provides practical guidance for working with and extending the Bus Reservation System. For complete API reference, see `API_DOCUMENTATION.md`.