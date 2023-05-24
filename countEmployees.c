#include "../include/headerA3.h"

//Counts amount of employees
int countEmployees (a3Emp * headLL){
    int numEmployees = 0;
    a3Emp *countHead = headLL;

    if (headLL == NULL){
        return 0;
    }

    //Increments counter
    while (countHead != NULL){
        countHead = countHead->nextEmployee;
        numEmployees++;
    }

    return numEmployees;
}