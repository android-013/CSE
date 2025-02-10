#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArrayByParityII(int* nums, int numsSize) {
    int evenIdx = 0, oddIdx = 1;

    while (evenIdx < numsSize && oddIdx < numsSize) {
        // Move evenIdx forward if nums[evenIdx] is correctly placed
        while (evenIdx < numsSize && nums[evenIdx] % 2 == 0) {
            evenIdx += 2;
        }
        // Move oddIdx forward if nums[oddIdx] is correctly placed
        while (oddIdx < numsSize && nums[oddIdx] % 2 == 1) {
            oddIdx += 2;
        }
        // Swap misplaced elements
        if (evenIdx < numsSize && oddIdx < numsSize) {
            swap(&nums[evenIdx], &nums[oddIdx]);
        }
    }
}

// Function to print the array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int nums[] = {4, 2, 5, 7};
    int size = sizeof(nums) / sizeof(nums[0]);

    sortArrayByParityII(nums, size);
    
    printf("Sorted array: ");
    printArray(nums, size);  // Output: [4,5,2,7] or similar valid results

    return 0;
}
