#include <stdio.h>

int main()
{
    char name[50], college[100], dept[30];
    int age, sem;
    float cgpa;

    // Input student details
    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Age: ");
    scanf("%d", &age);

    printf("Enter College Name: ");
    scanf(" %[^\n]", college);

    printf("Enter Department: ");
    scanf("%s", dept);

    printf("Enter Semester: ");
    scanf("%d", &sem);

    printf("Enter CGPA: ");
    scanf("%f", &cgpa);

    // Display student profile
    printf("\n----- STUDENT PROFILE -----\n");
    printf("Name        : %s\n", name);
    printf("Age         : %d\n", age);
    printf("College     : %s\n", college);
    printf("Department  : %s\n", dept);
    printf("Semester    : %d\n", sem);
    printf("CGPA        : %.2f\n", cgpa);

    return 0;
}
