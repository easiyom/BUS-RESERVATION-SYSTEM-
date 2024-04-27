#include "SignUp.c"
int LogIn(){
    int vote, vote2; 
    getchar(); 
    char username[USER_LENGTH];
    char password[PASSWORD_LENGTH]; 
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password); 
    for (int i = 0; i < numusers; i++){
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0){
            printf("Login successful. Wellcome, %s!\n", username);
            printf("Send 2 to exit.\n");
            scanf("%d", &vote); 
            if(vote == 1){
                printf("exiting...\n"); 
                exit(0); 
            }
            return 1; 
        }
    }
    printf("Login failed. Invalid username or password.\n");
    printf("\nsend 1 to Exit.\n");
    scanf("%d", &vote2); 
    switch (vote2)
    {
    case 1:
        exit(0); 
        break;
    
    default:
        break;
    }
    return 0; 
}