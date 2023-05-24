#include "../include/headerA3.h"

//Deletes all employees
void fireAll (a3Emp ** headLL){
   a3Emp *temp;

   if (*headLL == NULL){
        printf("\nError: List is empty.\n");
        return;
   }

   //Traverse the LL
    while (*headLL != NULL) {
        temp = *headLL;
        *headLL = (*headLL)->nextEmployee;

        //Free any dynamically allocated memory within the node
        for (int i = 0; i < temp->numDependents; i++) {
            free(temp->dependents[i]);
        }
        free(temp->dependents);

        //Free the node itself
        free(temp);
    }
    printf("All fired. Linked list is now empty.\n");
}