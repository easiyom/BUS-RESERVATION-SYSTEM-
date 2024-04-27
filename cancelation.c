#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registration.c"
void cancel(){
    FILE *inputFile, *outputFile;
    char Phone_number[12]; 
    char line[100]; 
    int found = 0; 

    printf("Enter the phone number to remove: "); 
    scanf("%s", Phone_number);
    Phone_number[strcspn(Phone_number, "\n")] = '\0'; 

    inputFile = fopen("registered.txt", "r");
    if(inputFile == NULL){
        printf("Error opening the file.\n"); 
        return; 
    }
    outputFile = fopen("temp.txt", "w");
    if(outputFile == NULL){
        printf("Error creating temporary file.\n");
        fclose(inputFile); 
        return; 
    }
    while(fgets(line, sizeof(line), inputFile)){
        if(strstr(line, Phone_number) == NULL){
            fputs(line, outputFile); 
        }else{
            found = 1; 
        }
    }
    fclose(inputFile);
    fclose(outputFile);

    remove("registered.txt");
    rename("temp.txt", "registered.txt");

    if(found){
        printf("\nDear passenger you scuessfully cancel the Ticket.\n");
    }else{
        printf("The Phone number is not found!\n"); 
    }
}