#include "../include/headerA3.h"

//Prints nth node of LL
void printOne (struct employee * headLL, int whichOne){
    //Variable decleration
    a3Emp *tempHead = headLL;
    a3Emp *countHead = headLL;
    int numEmp = 0;

    //Checks if LL is NULL
    if(headLL == NULL){
        printf("\nError: List is empty.\n");
        return;
    }

    //Counts amount of employees and checks if position exists
    while (countHead != NULL){
        countHead = countHead->nextEmployee;
        numEmp++;
    }
    if (whichOne > numEmp || whichOne < 1){
        printf("\nError: Position does not exist.\n");
        return;
    }

    //Moves position of head
    for (int i = 1; i<whichOne; i++){
        tempHead = tempHead->nextEmployee;
        numEmp++;
    }

    //Prints employee information
    printf("\nEmployee id: %d", tempHead->empId);
    printf("\nFirst name: %s", tempHead->fname);
    printf("\nLast name: %s", tempHead->lname);
    printf("\nDependents [%d]: ", tempHead->numDependents);
    for (int i = 0; i<tempHead->numDependents; i++){
        if (i == tempHead->numDependents-1){
            printf("%s ", tempHead->dependents[i]);
        }
        else{
            printf("%s, ", tempHead->dependents[i]);
        }
    }
    printf("\n");
}