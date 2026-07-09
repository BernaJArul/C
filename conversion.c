#include <stdio.h>

int main()
{
    float c, f, km, m, hour, minute, days, hours;

    // Celsius to Fahrenheit
    printf("Enter temperature in Celsius: ");
    scanf("%f", &c);
    f = (c * 9 / 5) + 32;
    printf("Fahrenheit = %.2f\n\n", f);

    // Fahrenheit to Celsius
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &f);
    c = (f - 32) * 5 / 9;
    printf("Celsius = %.2f\n\n", c);

    // Kilometer to Meter
    printf("Enter distance in Kilometer: ");
    scanf("%f", &km);
    m = km * 1000;
    printf("Meter = %.2f\n\n", m);

    // Hour to Minute
    printf("Enter time in Hours: ");
    scanf("%f", &hour);
    minute = hour * 60;
    printf("Minutes = %.2f\n\n", minute);

    // Days to Hours
    printf("Enter number of Days: ");
    scanf("%f", &days);
    hours = days * 24;
    printf("Hours = %.2f\n", hours);

    return 0;
}
