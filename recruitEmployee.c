#include "../include/headerA3.h"

//Adds new employee information to end of LL
void recruitEmployee (struct employee ** headLL){
    //Variable decleration
    char yesNo = 'y';
    a3Emp *newNode = malloc(sizeof(a3Emp));
    int ascii = 0;
    newNode->nextEmployee = NULL;

    //Stores first and last name
    printf("\nEnter the first name of the employee: ");
    scanf("%s", newNode->fname);
    printf("Enter the last name of the employee: ");
    scanf(" %s", newNode->lname);
    
    //Allocates space and stores dependents
    newNode->dependents = NULL;
    newNode->numDependents = 0;
    while (yesNo == 'y' || yesNo == 'Y'){
        if(newNode->dependents == NULL){
            newNode->dependents = malloc(sizeof(char *)* 1);
        } 
        else {
            newNode->dependents = realloc(newNode->dependents, sizeof(char *)* (newNode->numDependents+1));
        }
        newNode->dependents[newNode->numDependents] = malloc(sizeof(char)*MAX_LENGTH);
        printf("\nEnter name of dependent# %d: ", newNode->numDependents+1);
        scanf("%s", newNode->dependents[newNode->numDependents]);
        printf("Do you have anymore dependents? ");
        scanf(" %c", &yesNo);
        newNode->numDependents++;
    }
    printf("\nYou have %d dependents.\n", newNode->numDependents);

    //Creates employee id
    for (int i = 0; i<strlen(newNode->fname); i++){
        ascii = ascii + newNode->fname[i];
    }
    newNode->empId = ascii + strlen(newNode->lname);
    if(*headLL != NULL){
        a3Emp *tempHead = *headLL;
        while(tempHead != NULL){
            while (newNode->empId == tempHead->empId){
                newNode->empId = rand() % 999 + 1;
            }
            tempHead = tempHead->nextEmployee;
        }
    }
    printf("\nYour computer-generated empId is %d\n", newNode->empId);

    //Puts new employee information at end of LL
    if(*headLL == NULL){
        *headLL = newNode;
    }
    else{
        a3Emp *lastNode = *headLL;
        while(lastNode->nextEmployee != NULL){
            lastNode = lastNode->nextEmployee;
        }
        lastNode->nextEmployee = newNode;
    }
}