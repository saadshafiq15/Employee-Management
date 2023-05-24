#include "../include/headerA3.h"

//Finds and returns postion of employee with specific employee ID
int lookOnId (struct employee * headLL, int whichEmpId){
    //Variable decleration
    int position = 1;

    //If LL is empty
    if (headLL == NULL){
        return -1;
    }

    //Finds position
    a3Emp *tempHead = headLL;
    while (tempHead != NULL){
        if (whichEmpId == tempHead->empId){
            return position;
        }
        tempHead = tempHead->nextEmployee;
        position++;
    }
    return -1;
}