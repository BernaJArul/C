#include <stdio.h>

int main() {
    int arr[] = {12, 45, 2, 67, 34, 9, 55}, n = 7;
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    printf("Maximum element: %d\n", max);
    return 0;
}
