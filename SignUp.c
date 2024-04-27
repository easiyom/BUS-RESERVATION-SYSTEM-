#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USER_LENGTH 50
#define PASSWORD_LENGTH 50

struct User{
    char username[USER_LENGTH]; 
    char password[PASSWORD_LENGTH]; 
}; 

struct User *users = NULL; 

int numusers = 0; 

void SignUp(){
    printf("\t\t\t\t Register here\n"); 
    struct User newUser; 
    printf("Enter username: ");
    scanf("%s", newUser.username); 

    printf("Enter Password: ");
    scanf("%d", newUser.password);

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