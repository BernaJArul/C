#include <stdio.h>

#define S 10
int h[S];

void insert(int k) {
    int i = k % S;
    while (h[i] != 0) i = (i + 1) % S;
    h[i] = k;
}

int search(int k) {
    int i = k % S, start = i;
    while (h[i] != 0) {
        if (h[i] == k) return i;
        i = (i + 1) % S;
        if (i == start) break;
    }
    return -1;
}

int main() {
    int keys[] = {12, 22, 45, 37}, n = 4;
    
    for (int i = 0; i < n; i++) insert(keys[i]);

    for (int i = 0; i < S; i++) printf("%d: %d\n", i, h[i]);

    printf("Found 22 at: %d\n", search(22));
    return 0;
}
