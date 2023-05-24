#include "../include/headerA3.h"

int main(){
    //Variable decleration
    int whichTask = 1;
    struct employee *headLL = NULL;
    int whichOne;
    int whichEmpId;
    int position;
    int namePosition;
    char whichName[100];
    int numEmployees;
    int whichOneFire;
    char yesNo;

    loadEmpData(&headLL, "proFile.txt");

    do {
        //Prints the menu
        printf ("\n****Here is the menu****\n\n");
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");

        printf("Choose a menu option: ");
        scanf("%d", &whichTask);

        //Has all of the tasks and prints the info
        switch (whichTask){
            //Add employee
            case 1:
                recruitEmployee(&headLL);
                break;
                
            //Print all employees
            case 2:
                printAll(headLL);
                break;
            
            //Print nth employee
            case 3:
                printf("\nEnter a position: ");
                scanf("%d", &whichOne);
                printOne(headLL, whichOne);
                break;

            //Search for employee with Id
            case 4:
                printf("\nEnter an employee ID: ");
                scanf("%d", &whichEmpId);
                position = lookOnId(headLL, whichEmpId);
                //If an error occurs
                if (position == -1){
                    printf("\nError: List is empty or could not find employee.\n");
                    break;
                }
                else{
                    //Takes head to position
                    a3Emp *tempHead = headLL;
                    for (int i = 1; i<position; i++){
                        tempHead = tempHead->nextEmployee;
                    }
                    //Prints employee information
                    printf("\nEmployee id: %d", tempHead->empId);
                    printf("\nFirst name: %s", tempHead->fname);
                    printf("\nLast name: %s", tempHead->lname);
                    printf("\nDependents: ");
                    for (int i = 0; i<tempHead->numDependents; i++){
                        if (i == tempHead->numDependents-1){
                            printf("and %s", tempHead->dependents[i]);
                        }
                        else{
                            printf("%s, ", tempHead->dependents[i]);
                        }
                    }
                    printf("\n");
                }
                break;
            
            //Search for employee with name
            case 5:
                printf("\nEnter the full name of the employee: ");
                getchar();
                fgets(whichName, MAX_LENGTH, stdin);
                whichName[strlen(whichName)-1] = '\0';
                namePosition = lookOnFullName(headLL, whichName);
                //If an error occurs
                if (namePosition == -1){
                    printf("\nError: List is empty or could not find employee.\n");
                    break;
                }
                else{
                    //Takes head to position
                    a3Emp *tempHead = headLL;
                    for (int i = 1; i<namePosition; i++){
                        tempHead = tempHead->nextEmployee;
                    }
                    //Prints employee information
                    printf("\nEmployee id: %d", tempHead->empId);
                    printf("\nFirst name: %s", tempHead->fname);
                    printf("\nLast name: %s", tempHead->lname);
                    printf("\nDependents: ");
                    for (int i = 0; i<tempHead->numDependents; i++){
                        if (i == tempHead->numDependents-1){
                            printf("and %s", tempHead->dependents[i]);
                        }
                        else{
                            printf("%s, ", tempHead->dependents[i]);
                        }
                    }
                    printf("\n");
                }
                break;

            //Count employees
            case 6:
                //Stores number of employees
                numEmployees = countEmployees(headLL);
                if (numEmployees == 0){
                    printf("\nError: List is empty.\n");
                    break;
                }
                printf("\nTotal number of employees = %d\n", numEmployees);
                break;

            //Sort employees with Id
            case 7:
                sortEmployeesId(headLL);
                break;
            
            //Remove nth employee
            case 8:
                numEmployees = countEmployees(headLL);
                printf("\nCurrently there are %d employees.", numEmployees);
                printf("\nWhich employee do you wish to fire - enter a value between 1 and %d: ", numEmployees);
                scanf("%d", &whichOneFire);
                if (whichOneFire > numEmployees || whichOneFire < 1){
                    printf("Error: Employee not found.\n");
                    break;
                }
                fireOne(&headLL, whichOneFire);
                if (numEmployees != 0){
                    printf("There are now %d employees.\n", countEmployees(headLL));
                }
                break;
            
            //Remove all employees
            case 9:
                printf("\nAre you sure you want to fire everyone: ");
                scanf(" %c", &yesNo);
                if (yesNo == 'y' || yesNo == 'Y'){
                    fireAll(&headLL);
                }
                break;
                
        }

    } while (whichTask >= 1 && whichTask <=9);

    //Free memory used
    clearList(headLL);

    return 0;
}