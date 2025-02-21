class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;         // Pointer for nums1's valid elements
            int j = n - 1;         // Pointer for nums2
            int k = m + n - 1;     // Pointer for the end of merged array in nums1
            
            // Merge from the end to the beginning
            while (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }
            }
            
            // If there are any remaining elements in nums2, copy them over.
            // No need to copy nums1's remaining elements since they are already in place.
            while (j >= 0) {
                nums1[k--] = nums2[j--];
            }
        }
    };
    