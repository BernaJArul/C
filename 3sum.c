#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 1. Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    // Initial allocation guesses. We adjust memory as needed.
    int capacity = 16;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    // 2. Fix the first element (i) and find the other two (left, right)
    for (int i = 0; i < numsSize - 2; i++) {
        // If the lowest fixed element is positive, the sum can never be 0
        if (nums[i] > 0) break;

        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                // Found a valid triplet! Resize result array if capacity is reached
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                // Allocate and store the triplet
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Advance pointers and skip duplicate values
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } 
            else if (sum < 0) {
                left++; // Sum is too small, move left pointer to increase it
            } 
            else {
                right--; // Sum is too large, move right pointer to decrease it
            }
        }
    }

    return result;
}
