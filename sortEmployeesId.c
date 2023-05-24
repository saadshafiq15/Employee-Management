#include "../include/headerA3.h"

//Prints employees sorted using employee ID
void sortEmployeesId(struct employee *headLL) {
    //Checks if NULL
    if (headLL == NULL) {
        printf("\nError: List is empty, unable to sort.\n");
        return;
    }

    //Variable decleration
    a3Emp *tempHead = headLL;
    int numEmp = countEmployees(headLL);
    int empId[numEmp];
    int x, y, temp, position;  

    //Fills the array with employee id
    for (int a = 0; a < numEmp; a++){
        empId[a] = tempHead->empId;
        tempHead = tempHead->nextEmployee;
    } 

    //Bubble sorts the array
    for (x = 0; x < numEmp - 1; x++){       
        for (y = 0; y < numEmp - x - 1; y++){          
            if (empId[y] > empId[y + 1]){               
                temp = empId[y];
                empId[y] = empId[y + 1];
                empId[y + 1] = temp;
            }
        }
    }

    //Finds the position of each employee and prints in order
    for (int i = 0; i < numEmp; i++){
        position = lookOnId(headLL, empId[i]);
        printOne(headLL, position);
    }
}
