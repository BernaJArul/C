#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char s[1001];
    if (scanf("%1000s", s) != 1) return 0;
    int frequency[10] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the current character is a digit
        if (s[i] >= '0' && s[i] <= '9') {
            frequency[s[i] - '0']++; // Convert char to array index
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d", frequency[i]);
        if (i < 9) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
