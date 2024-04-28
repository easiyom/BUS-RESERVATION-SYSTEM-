#include "SignUp.c"
int LogIn(){
    int found = 0; 
    FILE *inputfile1, *outputfile2;
    char line[100]; 
    getchar(); 
    char username[USER_LENGTH];
    char password[PASSWORD_LENGTH]; 
    printf("\n\n\t\t\t\t\tMembers LogIn\n");
    printf("\n\t\t\t Customer this was for Members only.\n");
    printf("\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\n\t\t\tEnter password: ");
    scanf("%s", password); 
    username[strcspn(username, "\n")] = '\0'; 
    password[strcspn(password, "\n")] = '\0'; 

    inputfile1 = fopen("CreatedAccount.xlsx", "r"); 
    if(inputfile1 == NULL){
        printf("Error during opening the file.\n");
        return 1; 
    }
    while (fgets(line, sizeof(line), inputfile1)) {
        char fileUsername[USER_LENGTH];
        char filePassword[PASSWORD_LENGTH];

        // Use sscanf to parse the line and extract username and password
        if (sscanf(line, "%s\t%s", fileUsername, filePassword) == 2) {
            // Compare extracted username and password with input
            if (strcmp(fileUsername, username) == 0 && strcmp(filePassword, password) == 0) {
                found = 1; // Both username and password match
                break; // Exit the loop
            }
        }
    }
 
    fclose(inputfile1); 
    if(found){
        printf("\n\t\t\t\tDear passenger you scuessfully LogIn.\n");
        getchar(); 
    }else{
        printf("\n\t\t\t\tLogin Failed! Incorrect password/username\n"); 
    }
}
