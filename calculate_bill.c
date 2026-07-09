#include <stdio.h>

int main()
{
    char customerName[50], productName[50];
    int quantity;
    float price, total;

    // Input details
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", customerName);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", productName);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    printf("Enter Price per Product: ");
    scanf("%f", &price);

    // Calculate total bill
    total = quantity * price;

    // Display bill
    printf("\n----- SHOPPING BILL -----\n");
    printf("Customer Name : %s\n", customerName);
    printf("Product Name  : %s\n", productName);
    printf("Quantity      : %d\n", quantity);
    printf("Price         : %.2f\n", price);
    printf("Total Bill    : %.2f\n", total);

    return 0;
}
