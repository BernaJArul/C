#include <stdio.h>

int main()
{
    char name[50], dept[30];
    int regNo;
    float m1, m2, m3, m4, m5, total, average;

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Register Number: ");
    scanf("%d", &regNo);

    printf("Enter Department: ");
    scanf("%s", dept);

    printf("Enter marks of 5 subjects: ");
    scanf("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);

    total = m1 + m2 + m3 + m4 + m5;
    average = total / 5;

    printf("\nStudent Name : %s", name);
    printf("\nRegister No  : %d", regNo);
    printf("\nDepartment   : %s", dept);
    printf("\nTotal Marks  : %.2f", total);
    printf("\nAverage      : %.2f", average);

    return 0;
}
