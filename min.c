#include <stdio.h>

int main() {
    int arr[] = {12, 45, 2, 67, 34, 9, 55}, n = 7;
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }

    printf("Minimum element: %d\n", min);
    return 0;
}
