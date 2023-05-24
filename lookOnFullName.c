#include "../include/headerA3.h"

//Searches for employee with full name and returns position
int lookOnFullName (struct employee * headLL, char whichName [100]){
    //Variable decleration
    int position = 1;
    char firstName[100];
    char lastName[100];
    
    //If LL is empty
    if (headLL == NULL){
        return -1;
    }

    //Splits full name into first and last
    char *token = strtok(whichName, " ");
    if (token != NULL) {
        strcpy(firstName, token);
        token = strtok(NULL, " ");
        if (token != NULL) {
            strcpy(lastName, token);
        }
    }

    //Finds position
    a3Emp *tempHead = headLL;
    while (tempHead != NULL){
        if (strcmp(firstName, tempHead->fname) == 0 && strcmp(lastName, tempHead->lname) == 0){
            return position;
        }
        tempHead = tempHead->nextEmployee;
        position++;
    }
    return -1;
}