#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10; // Extract the last digit and add to sum
        n /= 10;       // Remove the last digit
    }
    
    printf("%d\n", sum);
    return 0;
}
