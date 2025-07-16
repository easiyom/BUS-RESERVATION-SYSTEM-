# Bus Reservation System - API Documentation

## Overview

The Bus Reservation System is a command-line application built in C that provides a comprehensive interface for managing bus ticket reservations. The system includes user authentication, ticket booking, cancellation, and route management features.

## Table of Contents

1. [System Architecture](#system-architecture)
2. [Data Structures](#data-structures)
3. [Core APIs](#core-apis)
4. [User Interface Functions](#user-interface-functions)
5. [Utility Functions](#utility-functions)
6. [File Operations](#file-operations)
7. [Usage Examples](#usage-examples)
8. [Error Handling](#error-handling)

## System Architecture

The system is modular with the following components:

```
main.c → homePage.c → {Eticket.c, about.c, login.c, SignUp.c}
                          ↓
                     {Registration.c, cancelation.c, rule.c}
```

## Data Structures

### `struct User`
**File:** `SignUp.c`

Represents a user account in the system.

```c
struct User {
    char username[USER_LENGTH];  // Maximum 50 characters
    char password[PASSWORD_LENGTH];  // Maximum 50 characters
};
```

**Fields:**
- `username`: Unique identifier for the user account
- `password`: Authentication credential for the user

### `struct bus_route`
**File:** `Registration.c`

Represents available bus routes in the system.

```c
struct bus_route {
    char start_location[100];    // Departure city
    char end_location[100];      // Destination city
    char day[20];               // Day of the week
    bool available;             // Route availability status
};
```

**Fields:**
- `start_location`: Starting point of the bus route
- `end_location`: Destination of the bus route
- `day`: Day when the route is available
- `available`: Boolean indicating if the route is currently available

## Core APIs

### Main Entry Point

#### `int main()`
**File:** `main.c`

**Description:** Application entry point that initializes the system and displays the home page.

**Parameters:** None

**Returns:** `int` - Exit status (0 for success)

**Example:**
```c
int main() {
    HomePage();
    return 0;
}
```

## User Interface Functions

### Home Page

#### `void HomePage()`
**File:** `homePage.c`

**Description:** Displays the main menu and handles navigation to different system modules.

**Parameters:** None

**Returns:** `void`

**Menu Options:**
1. E-Ticket
2. About
3. LogIn
4. SignUp

**Example Usage:**
```c
HomePage();
// Displays:
// Welcome to ODDAA Integrated Transport SC.
// Select one of the following to proceed to ticketing
// 1. E-Ticket
// 2. About
// 3. LogIn
// 4. SignUp
// Put Your Choice Here: 
```

### E-Ticket Module

#### `void Eticket()`
**File:** `Eticket.c`

**Description:** Displays the e-ticketing menu with options for registration, cancellation, ticket viewing, and rules.

**Parameters:** None

**Returns:** `void`

**Menu Options:**
1. Registration
2. Cancellation
3. My Ticket
4. Rule

**Example Usage:**
```c
Eticket();
// Displays e-ticketing menu and handles user selection
```

#### `void myticket()`
**File:** `Eticket.c`

**Description:** Retrieves and displays ticket information for a passenger using their phone number.

**Parameters:** None (reads phone number from user input)

**Returns:** `void`

**File Dependencies:** Reads from `registered.xlsx`

**Example Usage:**
```c
myticket();
// Prompts: Enter the Phone-Number:
// Input: 0912345678
// Output: Displays passenger details if found
```

**Output Format:**
```
Name: [Passenger Name]
Phone Number: [Phone Number]
Departure: [Departure City]
Destination: [Destination City]
Day: [Travel Day]
Fee: [Ticket Fee]
```

### User Authentication

#### `void SignUp()`
**File:** `SignUp.c`

**Description:** Creates a new user account and stores credentials in a file.

**Parameters:** None (reads username and password from user input)

**Returns:** `void`

**File Operations:**
- Writes to `CreatedAccount.xlsx`
- Updates global user array in memory

**Example Usage:**
```c
SignUp();
// Prompts for username and password
// Creates account and confirms success
```

**Input Flow:**
```
Enter UserName: john_doe
Enter Password: mypassword123
Account created successfully.
```

#### `int LogIn()`
**File:** `login.c`

**Description:** Authenticates user credentials against stored account data.

**Parameters:** None (reads username and password from user input)

**Returns:** `int` - 1 for error, undefined for success

**File Dependencies:** Reads from `CreatedAccount.xlsx`

**Example Usage:**
```c
int result = LogIn();
// Prompts for credentials and validates against stored data
```

### Information Display

#### `void About()`
**File:** `about.c`

**Description:** Displays comprehensive company information and background.

**Parameters:** None

**Returns:** `void`

**Example Usage:**
```c
About();
// Displays ODAA Integrated Transport S.C. company information
```

#### `void rule()`
**File:** `rule.c`

**Description:** Displays bus travel rules and regulations.

**Parameters:** None

**Returns:** `void`

**Example Usage:**
```c
rule();
// Displays all travel rules and regulations
```

## Utility Functions

### Route Management

#### `bool check_route(struct bus_route routes[], int num_routes, char departure[], char destination[], char day[])`
**File:** `Registration.c`

**Description:** Validates if a specific bus route is available for the given parameters.

**Parameters:**
- `routes[]`: Array of available bus routes
- `num_routes`: Number of routes in the array
- `departure[]`: Departure city (case-insensitive)
- `destination[]`: Destination city (case-insensitive)
- `day[]`: Day of travel (case-insensitive)

**Returns:** `bool` - `true` if route is available, `false` otherwise

**Example Usage:**
```c
struct bus_route routes[] = {
    {"addis ababa", "jijiga", "monday", true}
};
bool available = check_route(routes, 1, "addis ababa", "jijiga", "monday");
// Returns: true
```

#### `void handle_bus_route_checking(struct bus_route routes[], int num_routes)`
**File:** `Registration.c`

**Description:** Interactive function to get route details from user and validate availability.

**Parameters:**
- `routes[]`: Array of available bus routes
- `num_routes`: Number of routes in the array

**Returns:** `void`

**Side Effects:** Exits program if route is not available

**Example Usage:**
```c
struct bus_route routes[] = {...};
handle_bus_route_checking(routes, 9);
// Prompts user for departure, destination, and day
// Validates and displays result
```

#### `void odda()`
**File:** `Registration.c`

**Description:** Initializes the predefined bus routes and calls route checking functionality.

**Parameters:** None

**Returns:** `void`

**Predefined Routes:**
- Addis Ababa → Jijiga (Monday)
- Addis Ababa → Gonder (Tuesday)
- Addis Ababa → Harar (Tuesday)
- Addis Ababa → BahirDar (Wednesday)
- Addis Ababa → Desie (Friday)
- Addis Ababa → Woldiya (Saturday)

**Example Usage:**
```c
odda();
// Initializes routes and prompts for route checking
```

### Registration System

#### `void Registration()`
**File:** `Registration.c`

**Description:** Complete passenger registration system including route validation and data storage.

**Parameters:** None

**Returns:** `void`

**Features:**
- Route availability checking
- Multi-passenger support (up to 4 passengers)
- Data validation and storage

**File Operations:** Writes to `registered.xlsx`

**Example Usage:**
```c
Registration();
// Complete registration workflow:
// 1. Check route availability
// 2. Collect passenger information
// 3. Store registration data
```

**Registration Flow:**
```
1. Route validation (departure, destination, day)
2. Number of passengers (max 4)
3. For each passenger:
   - Name
   - Phone Number
   - Departure
   - Destination
   - Day
4. Save to file and confirm
```

### Cancellation System

#### `void cancel()`
**File:** `cancelation.c`

**Description:** Cancels a ticket reservation using phone number identification.

**Parameters:** None (reads phone number from user input)

**Returns:** `void`

**File Operations:**
- Reads from `registered.txt`
- Creates temporary file for data manipulation
- Updates original file

**Example Usage:**
```c
cancel();
// Prompts: Enter the phone number to remove:
// Input: 0912345678
// Removes matching records and confirms
```

## File Operations

### File Structure

The system uses the following files for data persistence:

1. **`CreatedAccount.xlsx`** - User account storage
   - Format: `Name\t\tpassword\n`
   - Contains username and password pairs

2. **`registered.xlsx`** - Passenger registration data
   - Format: Tabulated passenger information
   - Contains booking details and passenger information

3. **`registered.txt`** - Alternative registration storage (used in cancellation)

### File Format Examples

**CreatedAccount.xlsx:**
```
Name                    password
john_doe               mypassword123
jane_smith             securepass456
```

**registered.xlsx:**
```
Name of Passenger    Phone Number    Departure        Destination      Day
John Doe            0912345678      addis ababa      jijiga           monday
Jane Smith          0987654321      addis ababa      gonder           tuesday
```

## Usage Examples

### Complete Booking Flow

```c
// 1. Start application
main();

// 2. User selects E-Ticket from home page
HomePage(); // User chooses option 1

// 3. User selects Registration from e-ticket menu
Eticket(); // User chooses option 1

// 4. System validates route and collects passenger data
Registration();
```

### User Account Creation and Login

```c
// 1. Create account
SignUp();
// User provides username and password

// 2. Login with created account
LogIn();
// User enters same credentials for authentication
```

### Ticket Management

```c
// 1. View existing ticket
myticket();
// User enters phone number to retrieve booking

// 2. Cancel ticket if needed
cancel();
// User enters phone number to cancel booking
```

## Error Handling

### Common Error Scenarios

1. **File Access Errors**
   ```c
   FILE *file = fopen("filename", "r");
   if (file == NULL) {
       printf("Error opening file.\n");
       return;
   }
   ```

2. **Memory Allocation Errors**
   ```c
   users = (struct User *)realloc(users, size);
   if (users == NULL) {
       printf("Memory allocation failed.\n");
       return;
   }
   ```

3. **Route Not Available**
   ```c
   if (!check_route(routes, num_routes, departure, destination, day)) {
       printf("Sorry, there is no available bus route...\n");
       exit(0);
   }
   ```

4. **Passenger Limit Exceeded**
   ```c
   if (passanger > 4) {
       printf("Sorry Passenger. You only allowed to Book Ticket Atmost for FOUR person.\n");
   }
   ```

5. **Authentication Failure**
   ```c
   if (!found) {
       printf("Login Failed! Incorrect password/username\n");
   }
   ```

### Input Validation

The system performs several input validations:

- **Case Insensitive Location Names**: Converts input to lowercase
- **Phone Number Format**: Accepts string format for phone numbers
- **Passenger Limit**: Maximum 4 passengers per booking
- **File Existence**: Checks file availability before operations

## Global Variables

### User Management
```c
struct User *users = NULL;  // Dynamic array of users
int numusers = 0;          // Counter for registered users
```

### Constants
```c
#define USER_LENGTH 50          // Maximum username length
#define PASSWORD_LENGTH 50      // Maximum password length
#define MAX_LINE_LENGTH 100     // Maximum line length for file operations
```

## Compilation Instructions

To compile the complete system:

```bash
gcc -o bus_reservation main.c -std=c99
```

**Note:** Due to the include structure, compiling `main.c` will include all necessary source files.

## Dependencies

### Standard Libraries
- `stdio.h` - Input/output operations
- `stdlib.h` - Memory management and program control
- `string.h` - String manipulation functions
- `stdbool.h` - Boolean type support
- `ctype.h` - Character type functions

### System Requirements
- C99 compatible compiler
- File system access for data persistence
- Console/terminal for user interaction

## Security Considerations

1. **Password Storage**: Passwords are stored in plain text (consider encryption for production)
2. **Input Validation**: Limited input sanitization (implement bounds checking)
3. **File Permissions**: Ensure appropriate file access permissions
4. **Memory Management**: Proper cleanup of dynamically allocated memory

---

*This documentation covers all public APIs, functions, and components in the Bus Reservation System. For implementation details or modifications, refer to the individual source files.*