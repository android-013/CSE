#include <stdio.h>

// Function to find the maximum possible sum of an ascending subarray
int maxAscendingSum(int* nums, int numsSize) {
    int max_sum = nums[0];  // Initialize max_sum with the first element
    int current_sum = nums[0];  // Initialize current sum

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            current_sum += nums[i];  // Add to current sum if ascending
        } else {
            if (current_sum > max_sum) {
                max_sum = current_sum;  // Update max sum if needed
            }
            current_sum = nums[i];  // Reset sum to the current element
        }
    }

    // Final check to update max_sum if the last subarray was the largest
    if (current_sum > max_sum) {
        max_sum = current_sum;
    }

    return max_sum;
}

// Example usage
int main() {
    int nums1[] = {10, 20, 30, 5, 10, 50};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", maxAscendingSum(nums1, size1)); // Expected: 65

    int nums2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", maxAscendingSum(nums2, size2)); // Expected: 150

    int nums3[] = {12, 17, 15, 13, 10, 11, 12};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d\n", maxAscendingSum(nums3, size3)); // Expected: 33

    return 0;
}
