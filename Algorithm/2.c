#include <stdio.h>

// Function to merge two sorted arrays
void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;  // Pointer for nums1 (excluding trailing zeros)
    int j = n - 1;  // Pointer for nums2
    int k = m + n - 1;  // Pointer for placing elements in nums1

    // Start merging from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    int m = 3, n = 3;

    printf("Original nums1: ");
    printArray(nums1, m + n);

    merge(nums1, m, nums2, n);

    printf("Merged nums1: ");
    printArray(nums1, m + n);

    return 0;
}
