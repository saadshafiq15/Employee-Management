#include "../include/headerA3.h"

//Prints entire LL employee records
void printAll (struct employee * headLL){
    //Variable decleration
    a3Emp *tempHead = headLL;
    int numEmp = 1;

    if (headLL == NULL){
        printf("\nError: List is empty.\n");
        return;
    }

    //Prints all employee records
    while(tempHead != NULL){
        printf("\nEmployee # %d:", numEmp);
        printf("\n\tEmployee id: %d", tempHead->empId);
        printf("\n\tFirst name: %s", tempHead->fname);
        printf("\n\tLast name: %s", tempHead->lname);
        printf("\n\tDependents [%d]: ", tempHead->numDependents);
        for (int i = 0; i<tempHead->numDependents; i++){
            if (i == tempHead->numDependents-1){
                printf("%s ", tempHead->dependents[i]);
            }
            else{
                printf("%s, ", tempHead->dependents[i]);
            }
        }
        printf("\n");
        numEmp++;
        tempHead = tempHead->nextEmployee;
    }
    //Prints amount of records shown
    printf("\nCurrently, there are %d employees.\n", numEmp-1);
}