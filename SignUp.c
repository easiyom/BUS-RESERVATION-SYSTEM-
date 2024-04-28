#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define USER_LENGTH 50
#define PASSWORD_LENGTH 50

struct User{
    char username[USER_LENGTH]; 
    char password[PASSWORD_LENGTH]; 
}; 

struct User *users = NULL; 

int numusers = 0; 

void SignUp(){
    printf("\t\t\t\t Sign Up\n"); 
    struct User newUser; 
    printf("\n\t\tEnter UserName: ");
    scanf("%s", newUser.username); 

    printf("\n\t\tEnter Password: ");
    scanf("%s", newUser.password);
    //Open file for writting
    FILE *file = fopen("CreatedAccount.xlsx", "a");
    if(file == NULL){
        printf("Error opening file.\n"); 
        return; 
    }
    fseek(file, 0, SEEK_END);
    bool isEmpty = ftell(file) == 0; 
    rewind(file); 
    if(isEmpty){
        fprintf(file, "Name\t\t\t\tpassword\n");
    }
    fprintf(file, "%-20s\t%-12s\t\n", newUser.username, newUser.password);
    fprintf(file, "\n"); 
    fclose(file); 
    printf("\n"); 
    //Allocate memory for the new user. 
    users = (struct User *)realloc(users, (numusers + 1) * sizeof(struct User));
    if(users == NULL){
        printf("Memory allocation failed.\n"); 
        return; 
    } 
    // copy the information of the new users into array. 
    strcpy(users[numusers].username, newUser.username);
    strcpy(users[numusers].password, newUser.password);
    printf("\nAccount created successfully.\n"); 
    numusers++; 
}
