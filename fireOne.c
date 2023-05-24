#include "../include/headerA3.h"

//Removes one employee
void fireOne(a3Emp **headLL, int whichOne) {
    //Variable declaration
    a3Emp *temp = *headLL;
    a3Emp *prevNode = NULL;

    //If LL is empty
    if (*headLL == NULL) {
        printf("\nError: List is empty.\n");
        return;
    }

    // Special case for removing the first employee
    if (whichOne == 1) {
        *headLL = temp->nextEmployee;
        printf("Employee [Id: %d] fired.\n", temp->empId);
        for (int i = 0; i < temp->numDependents; i++) {
            free(temp->dependents[i]);
        }
        free(temp->dependents);
        free(temp);
        return;
    }

    //Keeps track of previous node
    for (int i = 1; i < whichOne; i++) {
        if (temp == NULL) {
            printf("\nError: Employee not found.\n");
            return;
        }
        prevNode = temp;
        temp = temp->nextEmployee;
    }

    //Removes employee
    printf("Employee [Id: %d] fired.\n", temp->empId);
    prevNode->nextEmployee = temp->nextEmployee;
    for (int i = 0; i < temp->numDependents; i++) {
        free(temp->dependents[i]);
    }
    free(temp->dependents);
    free(temp);
}