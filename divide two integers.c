#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    // 1. Handle the strict 32-bit overflow edge case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // 2. Determine the final sign of the quotient
    int is_negative = (dividend < 0) ^ (divisor < 0);

    // 3. Cast to unsigned int to safely hold the absolute magnitude
    unsigned int abs_dividend = (dividend == INT_MIN) ? 2147483648U : (unsigned int)abs(dividend);
    unsigned int abs_divisor = (divisor == INT_MIN) ? 2147483648U : (unsigned int)abs(divisor);

    unsigned int quotient = 0;

    // 4. Clean bit-shifting subtraction using safe unsigned types
    while (abs_dividend >= abs_divisor) {
        unsigned int temp_divisor = abs_divisor;
        unsigned int multiple = 1;

        // Shift left safely without running into signed bitwise exceptions
        while (abs_dividend >= (temp_divisor << 1) && (temp_divisor << 1) > temp_divisor) {
            temp_divisor <<= 1;
            multiple <<= 1;
        }

        abs_dividend -= temp_divisor;
        quotient += multiple;
    }

    // 5. Handle the negative sign safely using unsigned arithmetic before final cast
    if (is_negative) {
        return (int)(~quotient + 1); // Two's complement representation of negative value
    }
    
    return (int)quotient;
}
