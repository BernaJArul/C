#include <stdio.h>

int main()
{
    char empName[50];
    int empId;
    float basicSalary, hra, da, grossSalary;

    // Input employee details
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", empName);

    printf("Enter Employee ID: ");
    scanf("%d", &empId);

    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary);

    // Calculate salary
    hra = 0.20 * basicSalary;
    da = 0.15 * basicSalary;
    grossSalary = basicSalary + hra + da;

    // Display employee details
    printf("\n----- EMPLOYEE DETAILS -----\n");
    printf("Employee Name : %s\n", empName);
    printf("Employee ID   : %d\n", empId);
    printf("Basic Salary  : %.2f\n", basicSalary);
    printf("HRA (20%%)     : %.2f\n", hra);
    printf("DA (15%%)      : %.2f\n", da);
    printf("Gross Salary  : %.2f\n", grossSalary);

    return 0;
}
